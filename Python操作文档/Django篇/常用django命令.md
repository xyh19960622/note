# Django系统常用命令
## 1.创建项目
django-admin startproject HelloWorld
## 2.模型拷贝
python manage.py inspectdb 
python manage.py inspectdb > models.py
## 3.启动命令
python manage.py runserver 0.0.0.0:8000
## 4.创建模型
django-admin startapp TestModel
## 5.同步表结构
python manage.py migrate

# Django常用包
1. from django.template.response import TemplateResponse
2. from django.shortcuts import render
3. import json
4. from django.http import HttpResponse
## 定时任务包

```python 
from apscheduler.scheduler import Scheduler
checkData = auto.autoClear()

sched = Scheduler()
@sched.interval_schedule(seconds=1800)
def mytask():
    print("check data overTime")
    checkData.timesubtraction()
    # print("发送短信??????")
    checkData.sendNote()
sched.start()
```