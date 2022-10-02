//implementing stacks using linked lists : "->" is used to refer to the member belonging to the struct "node" type objects.

#include<iostream>
#include <iomanip>
using namespace std;

struct node
{
    int info;
    node*next;
};
class queueType
{
    node *front;
    node *rear;

    public:
    queueType()
    {
        front=rear=NULL;
    }
    void addition(node *);
    node* createNewNode(int);
    int deletion();
    void display();
    int isEmpty();
};

node *queueType::createNewNode(int x){
    node *newptr;
    newptr=new node();
    newptr->info=x;
    newptr->next=NULL;
    return newptr;
}

void queueType::addition(node *newptr){
    int e;
    e=isEmpty();
    if (e==1){
        front=rear=newptr;
    }//empty queue
    else{
        rear->next=newptr;
        rear=newptr;
    }//non empty queue
}

int queueType::deletion(){
    int e,rem;
    node*temp;
    if (front==rear){
        rem=front->info;
        temp=front;
        front=rear=NULL;
        return temp->info;
        delete temp;
    }//queue is empty
    else{
        rem=front->info;
        temp=front;
        front=front->next;
        return temp->info;
        delete temp;
    }//non empty queue
}
void queueType::display()
{
    int e;
    e=isEmpty();
    if (e==1){
        cout<<"-- NOTHING TO DISPLAY :: QUEUE IS EMPTY "<<endl;
    }else{
        cout<<endl<<"-> CONTENTS OF THE QUEUE : from the front most to the rearmost end : "<<endl;
         node *temp;
        temp=front;
        for (temp=front; temp!=NULL; temp=temp->next){
            cout<<setw(3)<<temp->info;
        }
    }
    cout<<endl<<endl;
}

int queueType::isEmpty()
{
    if (front==NULL)  return 1;
    else return -1;

}
void operationList()
{
    cout<<endl<<endl;
    cout<<setw(40)<<"======================="<<endl;
    cout<<"\t \t QUEUE OPERATIONS"<<endl;
    cout<<"\t 1. Add elements into Queue"<<endl;
    cout<<"\t 2. Delete element from Queue"<<endl;
    cout<<"\t 3. Display the elements of the queue"<<endl;
    cout<<"\t 4. Check if Queue is empty"<<endl;
    cout<<setw(40)<<"======================="<<endl<<endl;
    return;
}

int main()
{

    cout<<setw(50)<<endl<<"** QUEUE IMPLEMENTATION USING LINKED LIST **"<<endl;
    int choice, ele, val,rem;
    char ch='y';
    node *temp1;
    queueType queue;
    do{
        operationList();
        cout<<"-> Select the operation you want to perform : ";
        cin>>choice;
        switch(choice){
        case 1: cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add the elements ** "<<endl;
                cout<<"-> Enter a value : ";
                cin>>val;
                temp1=queue.createNewNode(val);
                queue.addition(temp1);
                queue.display();
                break;

        case 2: cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Delete the elements ** "<<endl;
                rem=queue.isEmpty();
                if (rem==1){
                    cout<<"-- QUEUE is empty! Deletion not possible ! "<<endl;
                }else{
                    ele=queue.deletion();
                    cout<<"-> Element Deleted : "<<ele<<endl;
                    queue.display();
                }
                break;

        case 3: cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : DISPLAY the elements ** "<<endl;
                queue.display();
                break;

        case 4: cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Check emptiness ** "<<endl;
                ele=queue.isEmpty();
                if (ele==1)     cout<<endl<<"-> The Queue is Empty! "<<endl;
                else cout<<endl<<"-> The Queue is not Empty! "<<endl;
                break;

        default : cout<<endl<<"!! Select a valid operation !!"<<endl<<endl;
        }

        cout<<endl<<"-> Do you want to continue (y/n)? ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');

}
