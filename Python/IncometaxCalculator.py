#Income tax calculator for annual basic salary According to Income tax Act 1961 by the Indian Constitution
print("Welcome to The Income tax Calculator Program")
x=float(input("Enter Your Annual Basic Pay Excluding All the Allowances"))
if(x<=250000):
    print("You are not Eligible for Income Tax Return")
if(x>250000 and x<=500000):
    y=.05*x
    print("Your Income tax return for currently year is",y)
if(x>500000 and x<=1000000):
    y=12500+(.2*(x-500000))
    print("Your Income tax return for currently year is",y)
if(x>1000000):
    y=112500+(.3*(x-1000000))
    print("Your Income tax return for currently year is",y)
