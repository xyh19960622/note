https://blog.csdn.net/qq_36288025/article/details/82534508   参考链接没毛病
CentOs7 经历上述安装后会出现防火墙出错
vim /usr/bin/firewall-cmd， 将#！/usr/bin/python -Es 改为 #！/usr/bin/python2 -Es 即可解决问题
