# 安装Nginx
1. wget http://nginx.org/download/nginx-1.11.10.tar.gz
2. tar xf nginx-1.5.6.tar.gz
3. cd nginx-1.5.6
4. ./configure --prefix=/usr/local/nginx \       如需要进行sockte访问则可以进行./configure  --prefix=/usr/local/nginx --with-stream (可能报错，解决方法：1.yum -y install pcre-devel      2.yum -y install openssl openssl-devel)
5. make && make install
6. cd /usr/local/nginx
7. ./nginx   运行nginx  
> `错误处理 :如第7步没有任何反应，则说明启动成功，直接访问：你的ip  会弹出Welcome to nginx  否则检查80端口是否开启，nginx默认端口是80`
8. 附：端口永久开启: `firewall-cmd --zone=public --add-port=80/tcp --permanent ` 重启防火墙: `firewall-cmd --reload`  查看端口是否开启 `firewall-cmd --query-port=80/tcp`
# 安装uwsgi
`python3环境下`
1. pip3 install uwsgi
2. 创建测试文件 test.py 输入
```python
def application(env, start_response):
    start_response('200 OK', [('Content-Type','text/html')])
    return [b"Hello World"] # python3
```

3. 运行 uwsgi --http :8000 --wsgi-file test.py
4. 访问http://ip:8000 可以看见helloWorld则说明安装成功

# 创建uwsgi配置文件

```python
[uwsgi]
# 项目目录
chdir=/home/xyh/xyh/Cauchy
# 指定项目的application
module=Cauchy.wsgi:application
# 指定sock的文件路径
socket=/home/xyh/xyh/Cauchy/uwsgi.sock
# 进程个数
workers=5
pidfile=/usr/local/nginx/uswgi.pid
# 指定IP端口
#http=0.0.0.0:8997
# 指定静态文件
static-map=/static=/home/xyh/xyh/Cauchy/static
# 启用主进程
master=true
# 自动移除unix Socket和pid文件当服务停止的时候
vacuum=true
# 序列化接受的内容，如果可能的话
thunder-lock=true
# 启用线程
enable-threads=true
# 设置自中断时间
harakiri=1800
# 设置缓冲
post-buffering=4096
# 设置日志目录  先创建
daemonize=/home/xyh/xyh/Cauchy/uwsgi.log
```
1. 关闭nginx `killall -9 nginx`  若没有该命令则`yum install psmisc`
2. 运行uwsgi   uwsgi --ini cauchy.ini
# 修改Nginx配置文件
1. cd /usr/local/nginx/conf
2. vi nginx.conf
3. 末尾增加
```python
server {
    listen 8000; #暴露给外部访问的端口
    server_name localhost;
        charset utf-8;
        client_max_body_size 75M;
    location / {
        include uwsgi_params;
        uwsgi_pass unix:/home/xyh/SopManager/uwsgi.sock;
        uwsgi_param UWSGI_CHDIR /home/xyh/SopManager;
        uwsgi_param UWSGI_SCRIPT Cauchy.wsgi;
        uwsgi_read_timeout 1800;
    }
    location /static {
        expires 30d;
        autoindex on;
        add_header Cache-Control private;
        alias /home/xyh/SopManager/static/; #项目静态路径设置
    }
}
```
4. cd /usr/local/nginx/sbin
5. ./nginx
6. 访问网站：http://ip：8000/Cauchy <--这里是你django urls.py文件中的路径
# 安装Django(包含了channels,定时任务等)
1. pip install Django
2. pip install pymysql
3. pip install channels
4. pip install -U channels_redis
5. pip install apscheduler==2.1.2
