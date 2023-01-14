"""Python Program to find the area of triangle
take inputs from the user"""
p=float(input('Enter first side: '))
q=float(input('Enter second side: '))
r=float(input('Enter third side: '))
#calculate the semi-perimeter
s=(p+q+r)/2
#calculate the area
area=(s*(s-p)*(s-q)*(s-r))**0.5
print('The area of the triangle is ',area)