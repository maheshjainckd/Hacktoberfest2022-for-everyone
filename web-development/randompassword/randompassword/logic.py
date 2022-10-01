import random
n = int(input("Enter length : "))
choice_I_have = list("abcdefghijklnmopqrstuvwxyz")
caps = input("Do you need capital letter (y/n):  ")
if caps == 'y' or caps == 'Y':
    choice_I_have.extend(list("ABCDEFGHIJKLNMOPQRSTUVWXYZ"))

nums = input("Do you need numbers in your password (y/n):  ")
if nums == 'y' or nums == 'Y':
    choice_I_have.extend(list("0123456789"))

symbols = input("Do you need symbols (y/n):  ")
if symbols == 'y' or symbols == 'Y':
    choice_I_have.extend(list('''!@#$%^&*()_+{}"?><`~[]'''))


password = ""
for i in range(n):
    choosen = random.choice(choice_I_have)
    password += choosen

print(password)