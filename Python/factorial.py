#Code Contributed by @Senku01
# Factorial Using Recursion 
def f(n):
    if n==0:
        return 1
    
    return n* f(n-1)

#Takes User Input 
n= int(input("Enter the Number you wanna Find Factorial Of :"))
print(f(n))
