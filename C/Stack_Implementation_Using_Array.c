#include<stdio.h>
 
void push(int n);
void pop();
void peek();
void display();
int isFull();
int isEmpty();
void printMenu();
 
const int max=10;
int stack[max];
int top=-1;
 
int main(){
 int ch,num;
 do{
   printMenu();
   scanf("%d",&ch);
   switch(ch){
     case 1:
       if(isFull()==1){
         break;
       }
       printf("Enter number to add in stack: ");
       scanf("%d",&num);
       push(num);
       break;
  
     case 2:
       if(isEmpty()==1){
         printf("Stack is Empty\n");
       }
       else
         display();
       break;
  
     case 3:
       peek();
       break;
  
     case 4:
       pop();
       continue;
   }
 }while(ch!=5);
 
 return 0;
}
 
 
void push(int n){
 top++;
 stack[top]=n;
 }
 
 
void pop(){
 if(top==-1){
   printf("Stack is Empty");
 }
 else{
   printf("Element deleted from stack is :%d\n",stack[top--]);
   display();
 }
}
 
void peek(){
 if(isEmpty()==1){
   printf("Stack is Empty\n");
 }
 else
   printf("Top element of stack is: %d\n",stack[top]);
}
 
void display(){
 
 for(int i=top;i>=0;i--){
 printf("\t%d",stack[i]);
 }
 
}
 
int isFull(){
 if(top>=max-1){
   printf("Stack Overflow\n\n");
   return 1;
 }
 else{
  return 0;
 }
return 0;
}
 
int isEmpty(){
 if(top==-1){
   return 1;
 }
 else{
   return 0;
 }
}
 
void printMenu(){
 printf("\nEnter 1 to Push\n");
   printf("Enter 2 to Display\n");
   printf("Enter 3 to Peek\n");
   printf("Enter 4 to Pop\n");
   printf("Enter 5 to Exit\n\n");
   printf("Enter your Choice:");
}
