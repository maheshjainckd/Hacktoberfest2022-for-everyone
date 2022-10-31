# The problem was to find the number of possible ways to travel from the top left corner of a M x N grid to the bottom right corner such that you can only travel in two directions i.e. down and right

# The intial approach was to solve using a brute force recusive algo O(2^(m+n))
# It was later optimised using memoization O(m*n)

# Memoization was implemented using a dictionary d that would store the return values of recursive calls and returns saved values for redundant calls 

def gridTraveller(m,n,d = dict()):
    key = str(m)+','+str(n)

    if key in d or key[::-1] in d: # Checking for redundant calls
        if key in d:
            return d[key]
        else:
            return d[key[::-1]]

    else:
        if (m==1 and n==1): # Base case
            return 1
        elif m==0 or n==0: # Base case
            return 0

        d[key] = gridTraveller(m-1,n) + gridTraveller(m,n-1)  # Adding new value to dictionary
        return d[key]

print(gridTraveller(1,1)) # Ans: 1
print(gridTraveller(2,3)) # Ans: 3
print(gridTraveller(3,2)) # Ans: 3
print(gridTraveller(18,18)) # Ans: 2333606220