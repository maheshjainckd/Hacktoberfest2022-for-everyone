#Author's name : Priyanshi Rai
#Modification date : 5-october-2022

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
