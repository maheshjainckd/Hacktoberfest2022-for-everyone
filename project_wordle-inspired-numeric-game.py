import random
from colorama import Fore
print(Fore.CYAN+'''
    Game Name :- WORDLE INSPIRED NUMERIC GAME \n          
    Rules of Game are as follows:      
    1. You have to Guess the 5-digit number in at max 18 chances.
    2. The system will give the hint by giving the count of:
        i) Exist:- Correct Number at incorrect position.
        ii) Position:- Correct Number at correct positon. 
    NOTE:- 
    *IF YOU ENTER A NUMBER MULTIPLE TIMES IT WILL BE COUNTED AS DIFFERENT NUMBER EVERYTIME.
'''+Fore.RESET)

x = random.randint(10000,99999)
unknown = x

# print(x)

l = []        
w = 0
for num in range(5):
    l.append(x%10)
    x = x//10 
for chance in range(18):
    if chance == 6 or chance == 12:
        print(Fore.LIGHTBLUE_EX+'\nOne hint can be provided'+Fore.RESET)
        ques=input('\nPress Y for YES or any other key for NO: ')
        if ques == 'y' or ques == 'Y':
            user_ans=int(input(Fore.CYAN + '\nWhich Number you want to know?' + Fore.RESET))
            if user_ans == 1:
                print(Fore.LIGHTBLUE_EX+'\nFirst Number is :'+Fore.RESET,unknown//10000)
            elif user_ans == 2:
                hint = unknown//1000
                print(Fore.LIGHTBLUE_EX+'\nSecond number is :'+Fore.RESET,hint%10)
            elif user_ans == 3:
                hint = unknown//100
                print(Fore.LIGHTBLUE_EX+'\nThird Number is :'+Fore.RESET,hint%10)
            elif user_ans == 4:
                hint = unknown//10
                print(Fore.LIGHTBLUE_EX+'\nFourth number is :'+Fore.RESET,hint%10)
            elif user_ans==5:
                print(Fore.LIGHTBLUE_EX+'\nLast number is :'+Fore.RESET,unknown%10)
    p=0  #for exist
    e=0  #for position
    y=unknown
    user_input=input('\nEnter A FIVE digit Number: ')    
    if user_input.isdigit():
            cpy1=int(user_input)
            cpy2=int(user_input)  
            if cpy1 in range(10000,100000):
                if cpy1==unknown:
                    print(Fore.GREEN+'\nYou guessed correct\nCongratulations you have won the NUMERIC WORDLE'+Fore.RESET)
                    print(Fore.GREEN+'You Took'+Fore.RESET,Fore.MAGENTA+str(chance)+Fore.RESET,Fore.GREEN+'guess'+Fore.RESET)
                    w=1
                    break
                else:
                    a=0
                    for exist in range(5):
                        if y%10==cpy2%10:
                            e=e+1
                        y=y//10

                        cpy2=cpy2//10
                    for pos in range(5):
                        if cpy1%10 in l:
                            p+=1
                        cpy1=cpy1//10
                print(Fore.YELLOW+'\nNumbers exists: '+Fore.RESET,p,Fore.GREEN+'\nNmbers at correct position:'+Fore.RESET,e)
            else:
                print(Fore.RED+'Invalid Input: Value out of range 10000-99999'+Fore.RESET)
    elif user_input.isalpha():
        print(Fore.RED+'Invalid Input: String value not allowed'+Fore.RESET)
    elif user_input.isalnum():
        print(Fore.RED+'Invalid Input: Enter only Intergral Value'+Fore.RESET)
    else:
        print(Fore.RED+'Invalid Input: Special Character or Symbols Not allowed'+Fore.RESET)
if w!=1:
    print(Fore.RED+'END OF GAME!!!'+Fore.RESET)
    print(Fore.RED+'You have ran out of turns: '+Fore.RESET)
    print(Fore.GREEN+'Correct guess is: '+Fore.RESET,unknown)