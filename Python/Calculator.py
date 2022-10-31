#Program make a simple calculator
print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")
print("5.Modulo")
while True:
    #Take input from the user
    choice = input("Enter your choice: ")
    #Check if choice is one of the four options
    if choice in('1','2','3','4'):
        a = float(input("Enter first number: "))
        b = float(input("Enter second number: "))
        if choice=='1':
            sum=a+b
            print(a,"+",b,"=",sum)
        elif choice=='2':
            sub=a-b
            print(a,"-",b,"=",sub)
        elif choice=='3':
            mul=a*b
            print(a,"*",b,"=",mul)
        elif choice=='4':
            div=a/b
            print(a,"/",b, "=",div)
        break
    else:
        print("Invalid Input!!")