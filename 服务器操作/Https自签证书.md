本地路由地址/etc/hosts设置Nginx   server_name
# https需重新makeNginx
## 步骤一：我们先来到当初下载nginx的包压缩的解压目录
## 步骤二：来到解压目录下后，按顺序执行一下命令：命令1、./configure --with-http_ssl_module  //重新添加这个ssl模块注意如果没有出现错误，则直接看命令2即可 命令出现这个错误（./configure：错误：SSL模块需要OpenSSL库。），原因是因为缺少了OpenSSL，那我们再来安装一个即可执行：yum -y installopenssl openssl-devel 等待OpenSSL的安装完成后，再执行./configure ，最后在执行” 命令1" 即可。
## 命令2、执行make命令，但是不要执行make install，因为make是用来编译的，而make install是安装，不然你整个nginx会重新覆盖的。
## 命令3、在我们执行完做命令后，我们可以查看到在nginx解压目录下，objs文件夹中多了一个nginx的文件，这个就是新版本的程序了。首先我们把之前的nginx先备份一下，然后把新的程序复制过去覆盖之前的即可。
## cp /usr/local/nginx/sbin/nginx /usr/local/nginx/sbin/nginx.bak
## cp objs/nginx /usr/local/nginx/sbin/nginx
## 命令4，最后我们来到Nginx安装目录下，来查看是否有安装ssl模块成功。执行./sbin/nginx -V即可看到如下图：
