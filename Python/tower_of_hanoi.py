#Author's name : Priyanshi Rai
#Modification date : 5-october-2022

#---------------------------------------------------GUIDELINES---------------------------------------------------------------------------------------

#1.) Create a tower_of_hanoi recursive function and pass two arguments: the number of disks n and the name of the rods such as source, aux, and target.
#2.) We can define the base case when the number of disks is 1. In this case, simply move the one disk from the source to target and return.
#3.) Now, move remaining n-1 disks from source to auxiliary using the target as the auxiliary.
#4.) Then, the remaining 1 disk move on the source to target.
#5.) Move the n-1 disks on the auxiliary to the target using the source as the auxiliary.

---------------------------------------------------------------------------------------------------------------------------------------------------------


##Program to solve the Tower of Hanoi problem using python

# Creating a recursive function  
def tower_of_hanoi(disks, source, aux , target):  
    if(disks == 1):  
        print('Move disk 1 from rod {} to rod {}.'.format(source, target))  
        return  
    # function call itself 
    
    tower_of_hanoi(disks - 1, source, target, aux)  
    print('Move disk {} from rod {} to rod {}.'.format(disks, source, target))  
    tower_of_hanoi(disks - 1, aux, source, target)  
  
 #enter the number of disk 
disks = int(input('Enter the number of disks: '))  

# We are referring source as A, auxiliary as B, and target as C 

tower_of_hanoi(disks, 'A', 'B', 'C')  
# Calling the function  
