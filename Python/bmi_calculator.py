#bmi calculator 

height=float(input("Enter height in cm: "))
weight=float(input("Enter Weight in kg: "))
BMI=weight/(height/100)**2
print(f'Your BMI is {BMI}')
if BMI <= 18.4:
  print("You underweight")
elif BMI <= 24.9:
  print("you are healthy ")
elif BMI <= 29.9:
  print("you are over weight")
elif BMI <= 34.9:
  print("you are severely over weight ")
elif BMI <= 39.9:
  print("obese ")
else:
  print("you severely obese  ")
  
