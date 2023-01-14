

// Delete a Node

#include<bits/stdc++.h>
using namespace std;

struct node{   
    int data;
    struct node *next;
};

void deleteNode(struct node **head, int key)
{     
     //Write your code here
     struct node *temp;
     
     if(*head->data == key){
         temp = *head;
         *head = (*head)->next;
         free(temp);
     }
     else{
         struct node *current = *head;

         while(current->next != NULL){
             
         if(current->next->data == key){
             temp = current->next;
             current->next = current->next->next;
             free(temp);
             break;
         }
         else{
             current = current->next;
         }
      }
    }
}

//Don't change the below code
void addLast(struct node **head, int val)
{   
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    
    if(*head == NULL)
         *head = newNode;
    else
    {   
        struct node *lastNode = *head;

        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    }

}

void printList(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
         printf("%d ", temp->data);
         temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;

    addLast(&head,10);
    addLast(&head,20);
    addLast(&head,30);

    int key;
    scanf("%d",&key);

    deleteNode(&head, key);

    printList(head);

    return 0;
}




// OR
