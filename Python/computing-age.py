birth_Year = int(input("Enter birth year"))
age = ""
current_Year = 2022 

age = current_Year - birth_Year

print("Your age is " + str(age))

if age <= 18:
    print("You are still a minor.")
else:
    print("You are now an adult!")