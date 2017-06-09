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