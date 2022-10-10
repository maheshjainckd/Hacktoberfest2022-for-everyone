from random import randint

#create a list of play options
t = ["Rock", "Paper", "Scissors"]

#assign a random play to the computer
computer = t[randint(0,2)]
your_score = 0
computer_score = 0
#set player to False
player = False
print(''' + "Welcome to Rock, Paper, Scissors! Type 'quit' to exit the game." + ''')
while player == False:
#set player to True
    player = input("Rock, Paper, Scissors?")
    if player == computer:
        print("Tie!")
    elif player == "Rock":
        if computer == "Paper":
            print("You lose!", computer, "covers", player)
            computer_score += 1
        else:
            print("You win!", player, "smashes", computer)
            your_score += 1
    elif player == "Paper":
        if computer == "Scissors":
            print("You lose!", computer, "cut", player)
            computer_score += 1
        else:
            print("You win!", player, "covers", computer)
            your_score += 1
    elif player == "Scissors":
        if computer == "Rock":
            print("You lose...", computer, "smashes", player)
            computer_score += 1
        else:
            print("You win!", player, "cut", computer)
            your_score += 1
    else:
        print("That's not a valid play. Check your spelling!")
    if player == "quit":
        print("Your score is", your_score)
        print("The computer's score is", computer_score)
        if your_score > computer_score:
            print("You win!")
        break
    
    #player was set to True, but we want it to be False so the loop continues
    player = False
    computer = t[randint(0,2)]
