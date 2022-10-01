# Guess the number game
# no of guesses 9
# no of guesses left
# game over

n=18
remain_guess=9
guess=1
while(guess<=9):
    print("----------------------")
    inp = int(input("\nEnter a guessing number:"))
    if inp<18:
        print("The number is greater than the one u entered\n")
    elif inp>18:
        print("The number is smaller than the one u entered\n")
    else:
        print("Yeah!! u guessed it right..the number is 18\n")
        print("No of guesses u took", guess)
        break
    guess = guess + 1
    remain_guess = remain_guess - 1
    print("Remaining guesses are " + str(remain_guess) + "\n")

if(remain_guess==0):
        print("----Game over...sorry u lose..try again----")
