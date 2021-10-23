#include<iostream>
#include<cstdio>

using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

void printList(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
}

void addNodeAtEnd(Node* head, int x){
   while(head->next!=NULL){
      head = head->next;
    }
  
    head->next = new Node(x);
  
}

Node* addNodeAtBeginning(Node* head, int x){
    Node* new_head = new Node(x);
    
    if(!head){
      return new_head;
    }

    new_head->next = head;

    return new_head;
}

int main(){

  Node* head = new Node(20);

  head->next = new Node(30);

  head->next->next = new Node(40);

  printList(head);
  
  cout<<endl;
  
  addNodeAtEnd(head,50);
  
  Node* new_head = addNodeAtBeginning(head,10);
  
  cout<<"After addition"; 
  printList(new_head);
  cout<<endl;

  return 0;
}
