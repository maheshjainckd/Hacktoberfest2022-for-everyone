from django.http import HttpResponse
from django.shortcuts import render
import random

# This file is made by me - Jayant

def home(request):
    return render(request, 'index.html')


def password(request):
    length = int(request.GET.get('length'))
    isUpper = request.GET.get('uppercase')
    isNumber = request.GET.get('number')
    isSymbol = request.GET.get('symbol')
    choice_I_have = list("abcdefghijklnmopqrstuvwxyz")
    if isUpper == 'on':
        choice_I_have.extend(list("ABCDEFGHIJKLNMOPQRSTUVWXYZ"))
    if isNumber == 'on':
        choice_I_have.extend(list("0123456789"))
    if isSymbol == 'on':
        choice_I_have.extend(list('''!@#$%^&*()_+{}"?><`~[]'''))
    myPassword = ""
    for i in range(length):
        choosen = random.choice(choice_I_have)
        myPassword += choosen
    
    data = {
        'password': myPassword,
        'naam': "Jayant Saksham",
        "School": 'Saturn'
    }

    return render(request, 'password.html', data)


def contact(request):
    return render(request, 'contact.html')
