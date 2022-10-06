from django.db import models
from django.conf import settings

# Create your models here.


class Post(models.Model):

    user                 =  models.ForeignKey(settings.AUTH_USER_MODEL, on_delete  = models.CASCADE)

    title                =  models.CharField(max_length = 500)
    slug                 =  models.SlugField()
    body                 =  models.CharField(max_length = 500)
    featured_image       =  models.FileField(blank = True)

    def __str__(self):

        return f'self.user.full_name'