let age = prompt("Hi Enter your age to check licence eligibility")
age = Number.parseInt(age)
if(age<=17){
  alert("hi you are not eligible for driving license ")
}
else if(age == 18)
{
  alert("Please apply for driving licence")
}
else{
  alert("you are eligible for license")
  
}
