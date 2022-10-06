from enum import unique
from django.db import models

from django.conf import settings
# Create your models here.


class Profile (models.Model):

    user             =  models.OneToOneField(settings.AUTH_USER_MODEL, on_delete = models.CASCADE)

    username          =  models.CharField(max_length = 300, unique  = True, blank = True)


    def __str__(self):

        return f'self.username'