
// Inserting a node at beginning : O(1)

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void addFirst(int val){
    // Create new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    // make it point to head
    newNode->next = head;

    // make it head
    head = newNode;
}

void printList(){
    struct node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}
int main(){
    // last inserted will become first element.
    addFirst(25);
    addFirst(20);
    addFirst(10);
    addFirst(5);
    printList();
return 0;
}

