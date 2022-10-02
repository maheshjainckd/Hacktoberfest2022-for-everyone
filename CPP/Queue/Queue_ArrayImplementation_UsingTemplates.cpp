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
template <class t>
class queuetype{
	t Q[size];
	int front, rear;

	public:
	void addition(t a);
	t deletion();
	int isFull();
	int isEmpty();
	void display();
    void queueOperation(queuetype<t>);
	queuetype(){
		front=rear=-1;
	}
};

template <class t> void queuetype<t>::addition(t a){
	if (front==-1){
		front=rear=0;
		Q[rear]=a;
	}else{
		Q[++rear]=a;
	}
}

template <class t> t queuetype<t>::deletion(){
	t rem;
	if (front==rear){
		rem=Q[front];
		front=rear=-1;
	}else{
		rem=Q[front];
		front++;
	}
	return rem;
}

template <class t> queuetype<t>:: isEmpty(){
	int e;
	if (front==-1){
		return 1;
	}else{
		return -1;
	}
}
template <class t> queuetype<t>::isFull(){
	if (rear=size-1){
		return 1;
	}else{
		return -1;
	}
}
template <class t> void queuetype<t>::display(){
 	cout<<endl<<"-> Displaying the Queue : "<<endl;
	for (int i=0; i<=rear; i++){
		if (i>=front){
		cout<<"\t"<<Q[i];
		}else{
			cout<<"\t ___";
		}
	}
	for (int i=rear+1; i<size; i++){
		cout<<"\t ___";
	}
	cout<<endl<<endl;
}



template <class t> void queuetype<t>:: queueOperation(queuetype<t> queue){
    char ch='y';
    int choice;
    int rem;
    t ele,res;
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
				rem=queue.isEmpty();
				if (rem==1)	cout<<"Queue is Empty! "<<endl;
				else cout<<"Queue is not Empty! " <<endl;
				queue.display();
				break;

		case 5: cout<<endl<<"\t ** OPERATION CHOSEN : Checking for Overflow ** "<<endl<<endl;
				rem=queue.isFull();
				if (rem==1)	cout<<"Queue is Full! "<<endl;
				else cout<<"Queue is not Full! " <<endl;
				queue.display();
				break;
		}

		cout<<endl<<"-> Do you want to continue (y/n) : ";
		cin>>ch;
	}
	cout<<endl<<"\t\t *** PROGRAM ENDS HERE ***"<<endl<<endl;
	return ;
}
int main()
{
    cout<<setw(50)<<endl<<"** QUEUE IMPLEMENTATION USING ARRAY AND TEMPLATES**"<<endl;
    int choice,ele,res;
	char ch='y';
	string st_type;
	cout<<"\n-> Which type of Queue do you want to create (int/string/float)? : ";
	cin>>st_type;

	if (st_type=="int" || st_type=="INT"){
		queuetype<int> obj;
		obj.queueOperation(obj);
	}else if (st_type=="float" || st_type=="FLOAT"){
		queuetype<float> obj;
		obj.queueOperation(obj);
	}else if (st_type=="string" || st_type=="STRING"){
		queuetype<string> obj;
		obj.queueOperation(obj);
	} else{
		cout<<endl<<"!! INVALID CHOICE : INTEGER QUEUE HAS BEEN CHOOSEN BY DEFAULT"<<endl<<endl;
		queuetype<int> obj;
		obj.queueOperation(obj);
	}
    return 0;
}
