# nginx 从入门到精通
## nginx下的常用命令
1. nginx -v/V打印nginx的版本信息
2. ./nginx -s reload 重新载入配置文件(在不停止nginx服务的情况更新配置)
3. nginx -s stop 立刻停止服务
4. nginx -s quit 优雅的停止服务
5. nginx -s reopen 重新开始记录日志文件
6. nginx -?/h
7. nginx -c 使用指定配置文件
8. nginx -g 指定配置指令
9. nginx -p 指定运行目录
10. nginx -t/T 测试配置文件是否有语法错误

## nginx热部署
1. 首先通过ps -ef |grep nginx 查看nginx当前进程
2. cp nginx nginx.old 把现有nginx二进制文件备份一下，因为编译了新的nginx后只更换二进制文件
3. 进入objs文件夹 cp -r nginx /usr/local/nginx/sbin/ -f 把新编译好的二进制文件拷贝到sbin的目录中替换掉之前的nginx二进制文件
4. 给正在运行的nginx master进程发送一个信号，告诉它我们进行热部署了，做一次版本升级: kill -USR2 13195(13195为nginx master进程的号),这时候nginx master进程会新生成一个master进程，这个新的master进程使用了刚刚新复制过来nginx二进制文件来启动它，老的worker也在运行，新的master会生成新的worker,他们会平滑的把所有的请求过度到新的nginx二进制文件中
5. 使用 ps -ef|grep nginx 再看一下nginx进程状况，可以看到新老的master进程和worker进程都在运行，但是老的master和worker都不在监听80或者443端口了，新的请求，新的连接只会进程新的nginx进程中，这个时候我们需要给老的nginx进程发送信号，告诉它，请优雅的关闭你的worker进程。使用命令：kill -WINCH 13195(进程号)
6. 使用 ps -ef|grep nginx 再看一下nginx进程状况，可以看到老的worker进程已经退出了，但是老的master进程还在，这是为了防止新的nginx可能会有一些bug，这是为了给我们做版本回退，可以给这个进程发送reload命令，让他重新把worker进程拉起来，再把新版本关掉。就可以版本回退。

## 日志切割
### 当我们需要把以前的日志备份到另外的文件中，但是nginx还是正常运行的。
1. 把日志文件复制一份 mv access.log bak.log
2. 执行命令 ../sbin/nginx -s reopen,这时候看下目录会发现nginx重新生成了一个日志文件，这样就完成了日志切割。但这样其实很麻烦，可以写一个bash脚本来管理。

## 访问静态文件
1. 先确定静态文件目录，最好是绝对路径
2. 配置Nginx.conf
   + listen :监听端口
   + location :配置地址
     + alias :nginx安装目录下的某某文件夹
![](.img/2019-06-23-19-14-37.png)
3. 重新加载:nginx -s reload,注意，这里的配置会默认访问alias指定地址下的index.html文件
4. 这样方式的加载没有经过gzip压缩，经过gzip后文件大小会大幅度减少，通常是会打开gzip
![](.img/2019-06-23-20-47-26.png)没经过gzip压缩前
5. 打开gzip
   + gzip on: 打开gzip压缩
   + gzip_min_length 1; 最小压缩，小于1字节的文件将不进行压缩，因为http报文一次就发送出去了，所以没必要压缩
   + gzip_comp_level 2; 压缩级别
   + gzip_tepys text/plain application/x-javascript text/css application/xml text/javascript application/x-httpd-php image/jpeg image/gif image/png :压缩格式，只针对以上格式进行压缩，如果本来就是gzip或者没有包含的格式将不进行压缩
![](.img/2019-06-23-21-03-59.png)压缩后大小，由此可见访问静态文件时，gzip还是节约了很大的加载大小。
6. 访问静态目录，主要用于共享资源时方便查看，只需要打开autoindex即可
![](.img/2019-06-23-21-14-19.png)
<font color=red>注意：如果该目录下有index.html文件，访问时将自动跳转至该页面</font>

## 限制速度
### 因为公网带宽是非常有限的，当并发用户使用我们的带宽时会形成一个增强关系，我们可能会为了让用户访问一些大文件的时候去限制他的速度，以期望能分离出足够的带宽，让用户访问必要的一些小文件，如css,js等等，这个时候就可以使用set $limit_rate 1k;其中1K就表示每秒传输1Kb到浏览器中
![](.img/2019-06-23-22-30-51.png)

## 日志格式
1. 在http模块下有一个log_format指令，由它来定义日志的格式
![](.img/2019-06-23-22-42-43.png)
2. 对日志格式进行命名，为了给不同的域名定义不同的日志格式
![](.img/2019-06-23-22-43-15.png)
3. 在server请求里通过access_log 定义日志存放在哪里，以及日志格式，每个请求都可以独立设置日志格式以及日志存放目录
![](.img/2019-06-23-22-47-59.png)