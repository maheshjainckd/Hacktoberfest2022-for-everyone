#include <stdio.h>
#include <conio.h>
#define MAX 10

    int queue[MAX];
    int front =-1,rear =-1;
    int insert();
    int deleteElement();
    int peek();
    void display();
    void displayMenu();

int main(){
    int ch,val;
    do{
        displayMenu();
        printf("\nYour option: ");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                val = insert();
                printf("Value of inserted element in Queue is: %d ",val);

                break;

            case 2:
                val = deleteElement();
                if(val!= 0){
                printf("Value of deleted element from Queue is: %d ",val);
                }
                break;

            case 3:
                val = peek();
                printf("Value of first element in Queue is: %d ",val);
                break;

            case 4:
                display();
                break;

        }
    }while(ch!=5);

    return 0;
}

int insert(){
    int num;
    printf("Enter number to be inserted in Queue : ");
    scanf("%d",&num);
    if(rear == MAX-1)
        printf("\n Queue Overflow");
    if(front == -1 && rear == -1)
        front = rear =0;
    else
        rear++;
    queue[rear] =num;
    return queue[rear];
}

int peek(){
    return queue[front];
}

void display(){

    for(int i = front ; i<=rear;i++){
        printf("%d \t",queue[i]);
    }
}

int deleteElement(){
    int val;
    if(front ==-1 || front>rear){
        printf("\n Queue Underflow\n");
        return 0;
    }
    else{
        val = queue[front++];
        return val;
    }
}

void displayMenu(){
    printf("\n\n 1 to Insert Element");
    printf("\n 2 to Delete Element");
    printf("\n 3 to Peek Element");
    printf("\n 4 to Display Element");
    printf("\n 5 to Exit Element");
}
