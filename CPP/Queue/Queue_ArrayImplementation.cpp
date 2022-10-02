#include <iostream>
#include <iomanip>
using namespace std;

void operationList()
{
    cout<<endl<<endl;
    cout<<setw(40)<<"======================="<<endl;
    cout<<"\t \t QUEUE OPERATIONS"<<endl;
    cout<<"\t 1. Add elements into Queue"<<endl;
    cout<<"\t 2. Delete element from Queue"<<endl;
    cout<<"\t 3. Display the elements of the queue"<<endl;
    cout<<"\t 4. Check if Queue is empty"<<endl;
    cout<<"\t 5. Check if Queue is full"<<endl;
    cout<<setw(40)<<"======================="<<endl<<endl;
    return;
}

const int size=5;
class queuetype{
	int Q[size];
	int front, rear;

	public:
	void addition(int a);
	int deletion();
	int isFull();
	int isEmpty();
	void display();

	queuetype(){
		front=rear=-1;
	}
};

void queuetype::addition(int a){
	if (front==-1){
		front=rear=0;
		Q[rear]=a;
	}else{
		Q[++rear]=a;
	}
}

int queuetype::deletion(){
	int rem;
	if (front==rear){
		rem=Q[front];
		front=rear=-1;
	}else{
		rem=Q[front];
		front++;
	}
	return rem;
}

int queuetype:: isEmpty(){
	int e;
	if (front==-1){
		return 1;
	}else{
		return -1;
	}
}
int queuetype::isFull(){
	if (rear=size-1){
		return 1;
	}else{
		return -1;
	}
}
void queuetype::display(){
 	cout<<endl<<"-> Displaying the Queue : "<<endl;
	for (int i=0; i<=rear; i++){
		if (i>=front){
		cout<<setw(3)<<Q[i];
		}else{
			cout<<setw(4)<<"___";
		}
	}
	for (int i=rear+1; i<size; i++){
		cout<<setw(4)<<"___";
	}
	cout<<endl<<endl;
}

int main()
{
    cout<<setw(50)<<endl<<"** QUEUE IMPLEMENTATION USING ARRAY **"<<endl;
    int choice,ele,res;
	char ch='y';
	queuetype queue;
	while (ch=='y' || ch=='Y'){
		operationList();
		cout<<"-> What operation do you want to perform : ";
		cin>>choice;
		switch(choice){
		case 1: cout<<endl<<"\t ** OPERATION CHOSEN : Enter Elements ** "<<endl<<endl;
				cout<<"-> Enter the element in the queue : ";
				cin>>ele;
				queue.addition(ele);
				queue.display();
				break;

		case 2: cout<<endl<<"\t ** OPERATION CHOSEN : Delete Elements ** "<<endl<<endl;
				res=queue.deletion();
				cout<<" -- Element Deleted : "<<res<<endl;
				queue.display();
				break;
		case 3: cout<<endl<<"\t ** OPERATION CHOSEN : Display Queue ** "<<endl<<endl;
				queue.display();
				break;
		case 4: cout<<endl<<"\t ** OPERATION CHOSEN : Checking for Underflow ** "<<endl<<endl;
				res=queue.isEmpty();
				if (res==1)	cout<<"Queue is Empty! "<<endl;
				else cout<<"Queue is not Empty! " <<endl;
				queue.display();
				break;

		case 5: cout<<endl<<"\t ** OPERATION CHOSEN : Checking for Overflow ** "<<endl<<endl;
				res=queue.isFull();
				if (res==1)	cout<<"Queue is Full! "<<endl;
				else cout<<"Queue is not Full! " <<endl;
				queue.display();
				break;
		}

		cout<<endl<<"-> Do you want to continue (y/n) : ";
		cin>>ch;
	}
	cout<<endl<<"\t\t *** PROGRAM ENDS HERE ***"<<endl<<endl;
    return 0;
}
