# Linux

some projects on ubuntu

## 17.6.8 四 凌晨

    折腾了许久，总算在ubuntu上勉强装上了HTK。然而因为年代久远，录音的驱动早已不在支持，还得解决标注的问题= =
    不过至少发现了Linux的好处，非常优雅的系统～
    在这个环境里还是要多多码代码，准备先用python实现一些数据结构和算法，或者直接做一些题吧。正好都放进这个git库，也方便了win与此系统文件的同步。

## 17.6.8 四 下午

    掏出了紫书，可能做题会更有动力吧。一道c++和python的实战。

### UVA1585

  >There is an objective test result such as "OOXXOXXOOO". An'O'means a correct answer of a problem and an 'X' means a wrong answer. The score of each problem of this test is calculated by itself andits just previous consecutive 'O's only when the answer is correct. For example, the score of the 10th problem is 3 that is obtained by itself and its two previous consecutive 'O's.Therefore, the score of "OOXXOXXOOO" is 10 which is calculated by \1+2+0+0+1+0+0+1+2+3".You are to write a program calculating the scores of test results.
  使用c11的 `for(auto &c:line)` 循环遍历形式,类似python，优雅.
   `freopen("in","r",stdin)`   可以在有cout语句的地方使用，但是无法回复到重定向前状态。

## 17.6.9 五 中午

  conda换源时要把默认源同时删除，不能仅仅放置在末尾。
  以及看了django tutorial part1

```python

import django

django-admin startproject mysite

python manage.py runserver
#python manage.py runserver 8080

python manage.py startapp polls

#in polls/views.py
from django.http import HttpResponse

def index(request):
    return HttpResponse("Hello,it's polls index!")

#in polls/urls.py
from django.conf.urls import url

from . import views

urlpatterns=[
    url(r'^$',views.index,name='index'),
]

#in mysite/urls.py
from django.conf.urls import include,url
from django.contrib import admin

urlpatterns=[
    url(r'^polls/', include('polls.urls')),
    url(r'^admin/',admin.site.urls),
]

python manage.py runserver

```
