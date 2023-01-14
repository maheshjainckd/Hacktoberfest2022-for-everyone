
# Converting String to binary
# Using join() + ord() + format()
  
# initializing string 
test_str = "Ashutosh"
  
# printing original string 
print("The original string is : " + str(test_str))
  
# using join() + ord() + format()
# Converting String to binary
res = ''.join(format(ord(i), '08b') for i in test_str)
  
# printing result 
print("The string after binary conversion : " + str(res))
