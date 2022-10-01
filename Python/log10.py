# a program to approximate log a base 10 with bisection
def setMid(l, u):
    return (l + u) / 2


a = float(input())
l = 0
u = 0
n = a
while n != 0:
    n = n // 10
    u += 1
x = setMid(l, u)
while not abs(a - 10**x) <= (10**-10) * max(a, x**2):
    if 10**x > a:
        u = x
    elif 10**x < a:
        l = x
    x = setMid(l, u)
print("{:.6f}".format(x))