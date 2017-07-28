from django.db import models

# Create your models here.
class Topic(models.Model):
    """学习的主题"""
    text = models.CharField(max_length =200)
    date_added= models.DateTimeField(auto_now_add=True)

class Entry(models.Model):
    """concrete knowledge about topic"""
    topic =models.ForeignKey(Topic)
    text=models.TextField()
    date_added =models.DateTimeField(auto_now_add=True)
    
    class Meta:
        verbose_name_plural='entries'

def __str__(self):
    """返回模型字符串表示"""
    return self.text[:50] + "..."