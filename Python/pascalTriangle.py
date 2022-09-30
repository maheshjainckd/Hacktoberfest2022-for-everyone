n = int(input())
def solution1(n):
  for i in range(n):
      print(' '*(n-i), end='')
      print(' '.join(map(str, str(11**i))))
      
def solution2(n):
  for i in range(1, n+1):
    for j in range(0, n-i+1):
        print(' ', end='')
 
    # first element is always 1
    C = 1
    for j in range(1, i+1):
 
        # first value in a line is always 1
        print(' ', C, sep='', end='')
 
        # using Binomial Coefficient
        C = C * (i - j) // j
    print()
    
print("solution 1:" )
solution1(n)
print("solution 1:" )
solution2(n)
