# HANGMAN GAME
## Description

Hangman is a popular word guessing game where the player attempts to build a missing word by guessing one letter at a time. After a certain number of incorrect guesses, the game ends and the player loses.

You can try playing the game here https://hangmanwordgame.com/

--- 
### SETUP THE GAME CODE.

  * install git
  * `git clone https://github.com/devs-nest/hangman-test.git`
  * `python hangman` (to run code, you would be using python3) 

  
### List of Tasks ( Complete hangman function ):
### Task 1 (Setting up)
  
  * open `hangman.py`
  * Read the comments inside hangman function and read the code, to understand you can also use a debugger.

  ### Task 2 (LOPPING)
  When you run this program it will only take user's input once and then will stop
  * You have to take multiple inputs from the user, use a loop for this.
  * Statements like "welcome to the game" should only be printed once, take a note of this
  ### Task 3 (LIVES)
  A user should have limited no of chances to guess the correct word, your code should always show no of chances/lives and should reduce it when user guesses incorrectly.

  * Use a temp variable named remaining_lives for this and set it to 8 inside hangman function.
  * Correctly change the variable value, when user guesses incorrectly, also handle other corner cases(what happens when it turns 0).
  * Remaining lives should be visible to the user playing the game.

  ### Task 4 (HANGMAN IMAGES)

  Have a look at images.py, you have to print the desired image after every wrong guess.

  * count number of wrong input's given by the user.
  * use it select image from the list
  * print the image on the console.
  * Create a seperate function for this and call it from hangman
  
  ### TASK 5 (AVAILABLE LETTERS)
  Availabe Letters are the letters which have not been guessed by the user,
  for eg if the user has guessed `['e', 'a']` then it should return `bcdfghijklmnopqrstuvwxyz`

  * Complete get_available_letters function
 
  ### TASK 6 (INVALID INPUTS)
  You have to check that whether the user's input is valid or not based on the below conditions i.e input character should be from a-z and should only contain letter.
  * Write a function which resembles the one below and use it in hangman function
  * if input is invalid, display that and do not count it as a used life 
   
  ```
  function ifValid(input_character)
    condition : 
      * input length == 1
      * must be character from a-z
    return :
      true or false
  ```
  ### TASK 7 (GAME WON)
  Here you have to check whether the word has been correctly guessed or not.
  * Complete is_word_guessed function    
  ```
  function is_word_guessed
    secret_word: word guess by the user
    letters_guessed: list hold all the word guess by the user
    returns: 
      return True ( if user guess the world correctly )
      return False ( wrong selection )
  ```
  ### TASK 8 (HINT)
  We allow a user playing this game to ask for one hint, so whenever user types hint, we should display one letter which the user has not guessed and is present in the string.
  * hint can only be used once in a game
  * hint should not be counted as a invalid character
  
  ### TESTING
  * Go to Words.py and uncomment line 15 to 19 to test.
  * Test your code with multiple inputs to see if it works fine

  

