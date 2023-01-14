#Python program to find the largest number among the three input numbers
n1 = input("Enter first number: ")
n2 = input("Enter second number: ")
n3 = input("Enter third number: ")
#Finding Largest Number using conditional operators
if (n1 >= n2) and (n1 >= n3):
   largest = n1
elif (n2 >= n1) and (n2 >= n3):
   largest = n2
else:
   largest = n3
#Printing the final result
print("The largest number is", largest)