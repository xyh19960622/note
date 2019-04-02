[[TOC]]
# 常用命令
## Liunx常用命令
### 查看进程
netstat -anp|grep 80
### 查看服务
ps -ef | grep nginx
### 查看firewalld状态
systemctl status firewalld
### 开启防火墙
systemctl start firewalld
### 端口永久开启
firewall-cmd --zone=public --add-port=80/tcp --permanent 
### 重启防火墙
firewall-cmd --reload
### 查看端口是否开启 
firewall-cmd --query-port=80/tcp
### 关闭防火墙
systemctl stop firewalld.service

## uwsig常用命令
### uwsgi重启进程ID
uwsgi --reload uwsgi/uwsgi.pid

## nginx常用命令
### nginx做域名时记得配置host
sudo vi /etc/hosts

## svn常用命令
### svn上传到版本库
svn add 项目名
### 停止SVN命令
killall svnserve
### svn 提交到版本库
svn commit -m "注释" test.cpp