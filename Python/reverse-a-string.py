def reverse(str):
    res = ''
    for i in str:
        res = i + res
    return res


s = "Jarvis"
print("The original string  is : ", s)
print("The reversed string using extended slice operator  is : ", reverse(s))
