







from contextlib import nullcontext


class Node:
    def __init__(self,value=None):
        self.value=value
        self.next=None

class SlinkedList:
    def __init__(self):
        self.head=None
        self.tail=None

    def __iter__(self):
        node=self.head
        while node:
            yield node
            node=node.next

    
    def insert(self,value,location):
        Newnode=Node(value)
        if self.head==None:
            self.tail=Newnode
            self.head=Newnode
        
        elif location==0:
            Newnode.next=self.head
            self.head=Newnode

        elif location ==-1:
            Newnode.next=None
            self.tail.next=Newnode
            self.tail=Newnode

        else:
            temp=self.head
            index=0
            while index < location-1:
                temp=temp.next
                index+=1
            
            Nextnode=temp.next
            temp.next=Newnode
            Newnode.next=Nextnode

            if temp==self.tail:
                self.tail=Newnode

    
    def transverse(self):
        node=self.head

        while node is not None:
            print(node.value)
            node=node.next
    
    def search(self,val):
        node=self.head

        while node is not None:
            if node.value==val:
                print("yeet")
            node=node.next


    def delete(self,location):
        if location==0:
            if self.head==self.tail:
                self.head=None
                self.tail=None
            else:
                self.head=self.head.next

        elif location==-1:
            if self.head==self.tail:
                self.head=None
                self.tail=None
            
            else:
                node=self.head
                while node is not None:
                    if node.next==self.tail:
                        break
                    node=node.next
                
                node.next=None
                self.tail=node

        else:
            temp=self.head
            index=1
            # here we have taken one location back of the current node
            while index<location-1:
                temp=temp.next
                index+=1
            
            nextnode=temp.next
            temp.next=nextnode.next






singleLinkedList=SlinkedList()
singleLinkedList.insert(1,1)
singleLinkedList.insert(2,-1)
singleLinkedList.insert(3,-1)
singleLinkedList.insert(4,-1)



print([i.value for i in singleLinkedList])
singleLinkedList.transverse()
singleLinkedList.search(2)
singleLinkedList.delete(3)

print([i.value for i in singleLinkedList])


