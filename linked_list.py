from dataclasses import dataclass


class Node:
    def __init__(self,data):
       self.data=data
       self.next=None 

class LinkedList:
    def __init__(self):
        self.head=None

if __name__ == '__main__':
  
    # Start with the empty list
    llist = LinkedList()
  
