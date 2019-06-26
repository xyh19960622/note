# nginx 从入门到精通

## nginx 下的常用命令

1. nginx -v/V 打印 nginx 的版本信息
2. ./nginx -s reload 重新载入配置文件(在不停止 nginx 服务的情况更新配置)
3. nginx -s stop 立刻停止服务
4. nginx -s quit 优雅的停止服务
5. nginx -s reopen 重新开始记录日志文件
6. nginx -?/h
7. nginx -c 使用指定配置文件
8. nginx -g 指定配置指令
9. nginx -p 指定运行目录
10. nginx -t/T 测试配置文件是否有语法错误

## nginx 热部署

1. 首先通过 ps -ef |grep nginx 查看 nginx 当前进程
2. cp nginx nginx.old 把现有 nginx 二进制文件备份一下，因为编译了新的 nginx 后只更换二进制文件
3. 进入 objs 文件夹 cp -r nginx /usr/local/nginx/sbin/ -f 把新编译好的二进制文件拷贝到 sbin 的目录中替换掉之前的 nginx 二进制文件
4. 给正在运行的 nginx master 进程发送一个信号，告诉它我们进行热部署了，做一次版本升级: kill -USR2 13195(13195 为 nginx master 进程的号),这时候 nginx master 进程会新生成一个 master 进程，这个新的 master 进程使用了刚刚新复制过来 nginx 二进制文件来启动它，老的 worker 也在运行，新的 master 会生成新的 worker,他们会平滑的把所有的请求过度到新的 nginx 二进制文件中
5. 使用 ps -ef|grep nginx 再看一下 nginx 进程状况，可以看到新老的 master 进程和 worker 进程都在运行，但是老的 master 和 worker 都不在监听 80 或者 443 端口了，新的请求，新的连接只会进程新的 nginx 进程中，这个时候我们需要给老的 nginx 进程发送信号，告诉它，请优雅的关闭你的 worker 进程。使用命令：kill -WINCH 13195(进程号)
6. 使用 ps -ef|grep nginx 再看一下 nginx 进程状况，可以看到老的 worker 进程已经退出了，但是老的 master 进程还在，这是为了防止新的 nginx 可能会有一些 bug，这是为了给我们做版本回退，可以给这个进程发送 reload 命令，让他重新把 worker 进程拉起来，再把新版本关掉。就可以版本回退。

## 日志切割

### 当我们需要把以前的日志备份到另外的文件中，但是 nginx 还是正常运行的。

1. 把日志文件复制一份 mv access.log bak.log
2. 执行命令 ../sbin/nginx -s reopen,这时候看下目录会发现 nginx 重新生成了一个日志文件，这样就完成了日志切割。但这样其实很麻烦，可以写一个 bash 脚本来管理。

## 访问静态文件

1. 先确定静态文件目录，最好是绝对路径
2. 配置 Nginx.conf
   - listen :监听端口
   - location :配置地址 + alias :nginx 安装目录下的某某文件夹
     ![](.img/2019-06-23-19-14-37.png)
3. 重新加载:nginx -s reload,注意，这里的配置会默认访问 alias 指定地址下的 index.html 文件
4. 这样方式的加载没有经过 gzip 压缩，经过 gzip 后文件大小会大幅度减少，通常是会打开 gzip
   ![](.img/2019-06-23-20-47-26.png)没经过 gzip 压缩前
5. 打开 gzip
   - gzip on: 打开 gzip 压缩
   - gzip_min_length 1; 最小压缩，小于 1 字节的文件将不进行压缩，因为 http 报文一次就发送出去了，所以没必要压缩
   - gzip_comp_level 2; 压缩级别
   - gzip_tepys text/plain application/x-javascript text/css application/xml text/javascript application/x-httpd-php image/jpeg image/gif image/png :压缩格式，只针对以上格式进行压缩，如果本来就是 gzip 或者没有包含的格式将不进行压缩
     ![](.img/2019-06-23-21-03-59.png)压缩后大小，由此可见访问静态文件时，gzip 还是节约了很大的加载大小。
6. 访问静态目录，主要用于共享资源时方便查看，只需要打开 autoindex 即可
   ![](.img/2019-06-23-21-14-19.png)
   <font color=red>注意：如果该目录下有 index.html 文件，访问时将自动跳转至该页面</font>

## 限制速度

### 因为公网带宽是非常有限的，当并发用户使用我们的带宽时会形成一个增强关系，我们可能会为了让用户访问一些大文件的时候去限制他的速度，以期望能分离出足够的带宽，让用户访问必要的一些小文件，如 css,js 等等，这个时候就可以使用 set \$limit_rate 1k;其中 1K 就表示每秒传输 1Kb 到浏览器中

![](.img/2019-06-23-22-30-51.png)

## 日志格式

1. 在 http 模块下有一个 log_format 指令，由它来定义日志的格式
   ![](.img/2019-06-23-22-42-43.png)
2. 对日志格式进行命名，为了给不同的域名定义不同的日志格式
   ![](.img/2019-06-23-22-43-15.png)
3. 在 server 请求里通过 access_log 定义日志存放在哪里，以及日志格式，每个请求都可以独立设置日志格式以及日志存放目录
   ![](.img/2019-06-23-22-47-59.png)

## 反向代理

### 由于上游服务要处理非常复杂的业务逻辑而且还要强调开发效率，所以性能比较差，nginx 反向代理后，可以由一台 nginx 把请求按照负载均衡算法代理给多台上游服务器工作，这样就实现了水平扩展，在用户无感知的情况下添加上游服务器来提升性能，而当上游服务器出现问题的时候，nginx 可以自动的把请求从有问题，出现灾难的服务器转交给正常的服务器

1. 将 nginx 服务器，变更为上游服务器，通常上游服务器是不可访问的，这个时候可以在 listen 中将端口号变成 127.0.0.1:8080,这时只有本地的进程才可以来打开 8080 端口
   ![](.img/2019-06-23-23-34-05.png)
2. 停掉 nginx，防止之前的进程还可以打开端口：./nginx -s stop,再打开：./nginx
3. 使用 nginx 以外的服务器，如 OpenResty,UWSIG 等等。此处以 uwsig 为例。
   ![](.img/2019-06-25-21-19-40.png)
4. 添加 upstream 上游服务，如果有很多台上游服务可以依次添加到这里。
   ![](.img/2019-06-25-21-26-31.png)
5. proxy_pass 代理地址，当访问 listen 中指定端口时将自动访问到 upstream 上游服务中
   ![](.img/2019-06-25-22-44-17.png)
6. proxy_set_head 特性介绍：起指向作用，因为有了反向代理，在上游服务中取到的地址其实是反向代理这台机器的地址，如果想拿浏览器的地址作为我限制浏览器访问速度等功能的一个作用时，其实是拿不到的。所以通过 proxy_set_head 可以把一些值添加一条新的 header 发送给上游服务器，比如说 X-Real-Ip \$remote_addr,把 X-Real-Ip 的值设置为从远端浏览器上的 IP 地址
   ![](.img/2019-06-25-23-00-09.png)
7. proxy_cache 特性介绍：通常使用 Nginx 反向代理时，只有动态的请求，也就是不同的用户访问同一个 URL 看到的内容是不一样时，这个时候才会交由上游服务器处理，但是有一些内容可能一段时间不会发生变化，这个时候为了减轻上游服务的压力，我们就会让 Nginx 把上游服务器的静态内容缓存一段时间，比如缓存一天，在一天之内，即使上游服务器对这个内容的相应发生了变化我们也不管，我们只会去拿缓存中的内容向浏览器发生相应，因为 Nginx 的性能远远高于上游服务器，所以使用这样的特性，对于一些小的站点，会有非常大的性能提升。
8. 配置缓存服务器
   - 通过 proxy_cache_path 设置缓存路径，其中的 key 值是需要拿去使用的
   - ![](.img/2019-06-25-23-12-55.png)，意思是开拓了 10m 的共享内容，命名为 my_cache
   - 在需要做缓存的 url 地址下增加 proxyh_cache my_cache 是刚才开辟的共享内存
   - proxy_cache_key : 同一个 url 访问时对不同的用户展示的内容是不一样的，所以用户的变量就需要去放在 key 中，比如$host$uri,另外还加了一些参数$is_args$args,这些参数就指明了是哪个用户，哪些资源，这些作为一个整体的 key。
     ![](.img/2019-06-25-23-40-10.png)
   - proxy_cache_valid : 对于哪些响应不返回
   - 测试：先访问一次站点，然后停掉上游服务，看是否还能访问
