# Code by deepu13

# Python program to print binomial expansion series

'''
Question:
Given three integers, A, X and n, the task is to print terms of below binomial expression series. 
(A+X)n = nC0AnX0 + nC1An-1X1 + nC2An-2X2 +….+ nCnA0Xn 
'''

'''
Examples:
Input : A = 1, X = 1, n = 5
Output : 1 5 10 10 5 1
Input : A = 1, B = 2, n = 6
Output : 1 12 60 160 240 192 64 
'''

'''
Solution:
We know that for each value of n there will be (n+1) term in the binomial series. So now we use a simple approach and calculate the value of each element of the series and print it . 
nCr = (n!) / ((n-r)! * (r)!)
Below is value of general term. 
Tr+1 = nCn-rAn-rXr
So at each position we have to find the value of the general term and print that term .
'''

# Code:

# Function to calculate factorial of a number
def factorial(n):
    f = 1
    for i in range(2, n+1):
        f *= i
    return f
 
# Function to print the series
def series(A, X, n):

    # calculating the value of n!
    nFact = factorial(n)
 
    # loop to display the series
    for i in range(0, n + 1):
         
        # For calculating the value of nCr
        niFact = factorial(n - i)
        iFact = factorial(i)
 
        # calculating the value of A to the power k and X to the power k
        aPow = pow(A, n - i)
        xPow = pow(X, i)
 
        # Display the series
        print (int((nFact * aPow * xPow) / (niFact * iFact)), end = " ")
     
# Driver Code
A = 3; X = 4; n = 5
series(A, X, n)


'''
Output:
243 1620 4320 5760 3840 1024 
'''