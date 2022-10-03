
// Inserting a node at last : O(1)

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void addLast(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    // Finding & pointing to last Node
    if(head == NULL){
        head = newNode;
    }
    else{
        struct node *lastNode = head;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void printList(){
    struct node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){
    addLast(10);
    addLast(20);
    addLast(30);
    addLast(40);
    printList();

return 0;
}