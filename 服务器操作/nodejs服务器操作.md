# Node.js 部署服务器
1. 安装node.js
2. 安装 ：pm2 ，pm2是Nodejs后台管理工具
3. 记得重启服务器，原因不知
4.  使用pm2 开启项目 pm2 start app.js(项目入口)
5.  pm2 start app.js --watch   #实时监控app.js的方式启动，当app.js文件有变动时，pm2会自动reload
6.  pm2 stop all  #停止PM2列表中所有的进程



