'''
Steps followed:
1. Board Design
2. Update board (User input on board)
3. Play game
4. Handle turn (switch between X and O)
5. Check if game is over - Who wins
    - check for rows
    - check for column
    - check for diagonal
6. Check for Tie
7. Flip Player
8. Back to 2

Starting point computer case => 0
Instead of 1
'''
# Type Casting - Converting one data type into another
# Access a index position in list
# students =  ["Rohan", "Subham" , "Aditya", 'John', "Rutuja" ] # List Variable
# students[2] = "Manoj"
# print(students)
# userInput = int(input())
# board[userInput - 1] = "X"


'''Tic Tac Toe'''
# Design the board
board = [
        "-", "-", "-",
        "-", "-", "-",
        "-", "-", "-"
        ]

has_won = None  # To store the winner name

game_is_still_going = True  # To check if the game is still going on

current_player = "X"  #  To store the current player
  
# Display the board with updated user input
def display_board():
    print("\n")

    print(board[0] + " | " + board[1] + " | " + board[2] + "    1 | 2 | 3")
    print(board[3] + " | " + board[4] + " | " + board[5] + "    4 | 5 | 6")
    print(board[6] + " | " + board[7] + " | " + board[8] + "    7 | 8 | 9")
    print("\n")

# Check if current user has valid input or not 
def handle_turn(player):

    print(player + "'s turn")
    position = input("Choose a position between (1-9): ")

    # Check if input is valid
    valid = False
    while not valid:

        # Check if position is between 1 - 9
        while position not in ["1", "2", "3", "4", "5", "6", "7", "8", "9"]:
            position = input("Not valid postion! Please choose another position between (1-9): ")
        
        position = int(position) - 1

        # Check whether there is some input in that position or not
        if(board[position] == "-"):
            valid = True
        else:
            print("You can't overwrite a position!")

    board[position] = player
    display_board()

# Check if game over
def check_if_game_over():
    check_if_win()
    check_if_tie()

# Check if there is tie
def check_if_tie():
    global game_is_still_going
    if "-" not in board:
        game_is_still_going = False
        return True
    else:
        return False


# Check if someone won
def check_if_win():
    # Call the global variable to update who has won
    global has_won

    # Store the row wise winner
    row_winner = check_row_winner()
    # Store the column wise winner
    column_winner = check_column_winner()
    # Store the diagonal wise winner
    diagonal_winner = check_diagonal_winner()

    # Update the has_won with the winner name
    if row_winner:
        has_won = row_winner
    elif column_winner:
        has_won = column_winner
    elif diagonal_winner:
        has_won = diagonal_winner
    else:
    # If there is no winner than return None
        has_won = None

# Check for row wise winner 
def check_row_winner():
    global game_is_still_going
    row_1 = board[0] == board[1] == board[2] != "-"
    row_2 = board[3] == board[4] == board[5] != "-"
    row_3 = board[6] == board[7] == board[8] != "-"

    if row_1 or row_2 or row_3:
        game_is_still_going = False
    if row_1:
        return board[0]
    elif row_2:
        return board[3]
    elif row_3:
        return board[6]
    else:
        return None

# Check for column wise winner 
def check_column_winner():
    global game_is_still_going
    col_1 = board[0] == board[3] == board[6] != "-"
    col_2 = board[1] == board[4] == board[7] != "-"
    col_3 = board[2] == board[5] == board[8] != "-"

    if col_1 or col_2 or col_3:
        game_is_still_going = False
    if col_1:
        return board[0]
    elif col_2:
        return board[1]
    elif col_3:
        return board[2]
    else:
        return None

# Check for diagonal wise winner 
def check_diagonal_winner():
    global game_is_still_going
    diagonal_1 = board[0] == board[4] == board[8] != "-"
    diagonal_2 = board[2] == board[4] == board[6] != "-"

    if diagonal_1 or diagonal_2:
        game_is_still_going = False
    if diagonal_1:
        return board[0]
    elif diagonal_2:
        return board[2]
    else:
        return None
    

# Flip the current player to next player
def flip_player():
    # Call Global variable
    global current_player

    if current_player == "X":
        current_player = "O"
    elif current_player == "O":
        current_player = "X"

# Play the game
def play_game():
    display_board()
    
    # To check if the game is still running
    while game_is_still_going:
        handle_turn(current_player)
        check_if_game_over()
        flip_player()

    if has_won == "X" or has_won == "O":
        print("Our winner is "+has_won)
    elif has_won == None:
        print("Game Tie")

play_game()
