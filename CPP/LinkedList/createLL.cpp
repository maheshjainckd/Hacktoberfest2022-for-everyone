#include<iostream>
#include<cstdio>

using namespace std;

//class for creating nodes of list
//we can also use struct here
class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

//utility function to print List
void printList(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
}

int main(){

  Node* head = new Node(10);

  head->next = new Node(20);

  head->next->next = new Node(30);

  head->next->next->next = new Node(40);

  head->next->next->next->next = new Node(50);

  printList(head);

  return 0;
}
