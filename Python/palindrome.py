
# Author: Álvaro Masanori Sato

def check_palindrome(s):
    reversed_s = s[::-1]
    is_palindrome = 1
    if(s != reversed_s):
        is_palindrome = 0
    return is_palindrome


palindrome_input = input("Enter the string to be checked: ")
check = check_palindrome(palindrome_input)
if(check):
    print("Your string is palindrome")
else:
    print("Sorry! it's not a palindrome")