# 本地路由地址/etc/hosts设置Nginx   server_name
# 要使用https需重新makeNginx
## 步骤一：我们先来到当初下载nginx的包压缩的解压目录
## 步骤二：来到解压目录下后，按顺序执行一下命令：命令1、./configure --with-http_ssl_module  //重新添加这个ssl模块注意如果没有出现错误，则直接看命令2即可 命令出现这个错误（./configure：错误：SSL模块需要OpenSSL库。），原因是因为缺少了OpenSSL，那我们再来安装一个即可执行：yum -y installopenssl openssl-devel 等待OpenSSL的安装完成后，再执行./configure ，最后在执行” 命令1" 即可。
## 命令2、执行make命令，但是不要执行make install，因为make是用来编译的，而make install是安装，不然你整个nginx会重新覆盖的。
## 命令3、在我们执行完做命令后，我们可以查看到在nginx解压目录下，objs文件夹中多了一个nginx的文件，这个就是新版本的程序了。首先我们把之前的nginx先备份一下，然后把新的程序复制过去覆盖之前的即可。
## cp /usr/local/nginx/sbin/nginx /usr/local/nginx/sbin/nginx.bak
## cp objs/nginx /usr/local/nginx/sbin/nginx
## 命令4，最后我们来到Nginx安装目录下，来查看是否有安装ssl模块成功。执行./sbin/nginx -V即可看到如下图：

# 通过OpenSSL生成自签证书( CentOs7下自带OpenSSL )
## 1.创建服务器私钥，长度1024位, des3加密算法的
```
openssl genrsa -des3 -out server.key 1024

```
## 2.创建签名请求证书.csr
```
openssl req -new -key server.key -out server.csr 

Country Name (2 letter code) [AU]:CN
State or Province Name (full name) [Some-State]:Beijing
Locality Name (eg, city) []:Beijing
Organization Name (eg, company) [Internet Widgits Pty Ltd]:joyios
Organizational Unit Name (eg, section) []:info technology
Common Name (e.g. server FQDN or YOUR name) []:demo.joyios.com   这一项必须和你的域名一致
Email Address []:liufan@joyios.com

```


## 3. 在加载SSL支持的Nginx并使用上述私钥时除去必须的口令
```

cp server.key server.key.org
openssl rsa -in server.key.org -out server.key

```

## 4. 标记证书使用上述私钥和CSR 
```
openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt

```

# Https进行Socket访问时必须使用wss进行握手，以下是需要更改的配置信息
## 1. websocket = new WebSocket('wss://' + window.location.host +'/wss/chat');前端页面访问地址
## 2. Nginx配置信息
```
server{
        listen 443;
        server_name localhost1;
        charset utf-8;
        ssl on;
        ssl_certificate /usr/local/nginx/openssl/SSL.crt;
        ssl_certificate_key /usr/local/nginx/openssl/SSL.key;
    location / {
        include uwsgi_params;
        uwsgi_pass unix:/home/xyh/project/SopManager/uwsgi.sock;
        uwsgi_param UWSGI_CHDIR /home/xyh/project/SopManager;
        uwsgi_param UWSGI_SCRIPT Cauchy.wsgi;
        uwsgi_read_timeout 1800;
    }
    location /static {
        expires 30d;
        autoindex on;
        add_header Cache-Control private;
        alias /home/xyh/project/SopManager/static/; #项目静态路径设置
    }
     location /wss/chat {
        proxy_pass http://wsbackend; # 域名
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection "upgrade";
        proxy_redirect off;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Host $server_name;
  }
}

```
