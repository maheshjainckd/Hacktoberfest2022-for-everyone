import random

def display_board(fun):#fun referred here is board
    print("- - - - - - - ")
    print('| {a} | {b} | {c} |'.format(a=fun[1],b=fun[2],c=fun[3]))
    print("- - - - - - - ")
    print('| {a} | {b} | {c} |'.format(a=fun[4],b=fun[5],c=fun[6]))
    print("- - - - - - - ")
    print('| {a} | {b} | {c} |'.format(a=fun[7],b=fun[8],c=fun[9]))
    print("- - - - - - - ")
def place_marker(fun, marker, position):
    fun[position]=marker
def player_input():
    choice='wrong'
    while choice not in ['X','O']:
        choice=input("Enter a choice for Player 1:'X' or 'O':")
        if choice not in ['X','O']:
            # THIS CLEARS THE CURRENT OUTPUT BELOW THE CELL
            print("Sorry, but you did not choose a value in the range")
    return choice
def win_check(fun, mark):
    count=0
    if fun[1]==fun[2]==fun[3]==mark or fun[4]==fun[5]==fun[6]==mark or fun[7]==fun[8]==fun[9]==mark:
        count=1
    elif fun[1]==fun[4]==fun[7]==mark or fun[2]==fun[5]==fun[8]==mark or fun[3]==fun[6]==fun[9]==mark:
        count=1
    elif fun[1]==fun[5]==fun[9]==mark or fun[3]==fun[5]==fun[7]==mark:
        count=1
    if count==1:
        return True
    else:
        return False
import random 

def choose_first():
    x=random.randint(1,10)
    if x%2==0:
        return 'X'
    else:
        return 'O'
def space_check(board, position):
    if board[position]==int(position):
        return True
    else:
        return False
def full_board_check(board):
    for i in range(1,10):
        if space_check(board,i):
            return False
    return True
 
def player_choice(fun,mark):
    nextpos='0'
    while nextpos not in range(1,10):
        print("Enter a position (1-9) to be marked by {a}.".format(a=mark))
        nextpos=int(input())
        if nextpos not in range(1,10) and not space_check(fun,nextpos):
            # THIS CLEARS THE CURRENT OUTPUT BELOW THE CELL
            clear_output()
            print("Sorry, but you did not choose a value in the range or the space is occupied.")
    return nextpos

def replay():
        playagain=True
        while playagain not in ['Y','N']:
            playagain=input("Do you want to play again?( Enter 'Y' for yes or 'N' for no)")
            if playagain not in ['Y','N']:
                # THIS CLEARS THE CURRENT OUTPUT BELOW THE CELL
                clear_output()
                print("Sorry, but you did not choose a value in the range")
        if playagain=='Y':
            return True
        elif playagain=='N':
            return False

while replay()==True:
    board=[0,1,2,3,4,5,6,7,8,9]
    display_board(board)
    Player1=player_input()
    if Player1=='X':
        Player2='O'
    else:
        Player2='X'
    firstone = choose_first()
    print(firstone+' goes first.')
    gameplay=replay()
    while gameplay:
        if firstone==Player1:
            display_board(board)
            position=player_choice(board,Player1)
            while space_check(board,position):
                place_marker(board,Player1,position)
            
            if win_check(board,Player1):
                display_board(board)
                print(Player1+' has won.Congrats!')
                gameplay=False
            elif full_board_check(board):
                display_board(board)
                print('There is a Tie between Player 1 '+Player1+' and Player 2 '+Player2)
                gameplay=False
                break
            else:
                firstone=Player2
        elif firstone==Player2:
            display_board(board)
            position=player_choice(board,Player2)
            while space_check(board,position):
                place_marker(board,Player2,position)
                
            if win_check(board,Player2):
                display_board(board)
                print(Player2+' has won.Congrats!')
                gameplay=False
            elif full_board_check(board):
                display_board(board)
                print('There is a Tie between Player 1 '+Player1+' and Player 2 '+Player2)
                gameplay=False
                break
            else:
                firstone=Player1