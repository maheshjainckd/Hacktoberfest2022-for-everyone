from random import randint

print("You only have 3 chances to guess")
bil = randint(0, 30)
chance = 3

for chances in range(chance):
  #Input number
  number = int(input("input numbers 0 to 30="))
  if number == bil:
    print("hore,your prediction is right")
    break;
  elif number < bil:
    print("a little more your prediction is right, the number you enter is small")
  elif number > bil:
    print("a little more your prediction is right, the number you enter is big")
else:
  print(f"sorry,all your guesses wrong and answer {bil},thanks")