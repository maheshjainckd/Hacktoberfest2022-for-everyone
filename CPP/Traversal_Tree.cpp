#include<iostream>

using namespace std;

class tree
{
	tree *left, *right;
	public :
		char data;
		tree* create(char);
		tree* expression(char[]);
		void inorder(tree *);
		void ninorder(tree *);
		void preorder(tree *);
		void npreorder(tree *);
		void postorder(tree *);
};

class stack
{
	
	public :
		tree *t;
		stack *top, *link;
		stack()
		{
			top=NULL;
		}
		void push(tree *);
		void pop();
};

void stack::push(tree *item)
{
	stack *newnode = new stack();
	newnode->t=item;
	newnode->link=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->link=top;
		top=newnode;
	}
}

void stack::pop()
{
	if(top==NULL)
	{
		cout<<"\nStack is empty\n";
	}
	else
	{
		stack *ptr = top;
		top = top->link;
		delete ptr;
	}
}

tree* tree::create(char op)
{
	tree *nodenew = new tree();
	nodenew->data=op;
	nodenew->left=NULL;
	nodenew->right=NULL;
	return nodenew;
}

void tree::inorder(tree *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

void tree::ninorder(tree *root)
{
	stack s;
	//tree *curr=ptr3;
	while(1)
	{
		while(root)
		{
			s.push(root);
			root=root->left;
		}
		if(s.top!=NULL)
		{
			root=s.top->t;
			s.pop();
			cout<<root->data;
			root=root->right;
		}
		else
		 break;
	}
}

void tree::preorder(tree *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}

void tree::npreorder(tree *root)
{
	stack s;
	//tree *curr=ptr5;
	while(1)
	{
		while(root)
		{
			cout<<root->data;
			if(root->right)
			{
				s.push(root->right);
			}
			root=root->left;
		}
		if(s.top!=NULL)
		{
			root= s.top->t;
			s.pop();
		}
		else
		 break;
	}
}

void tree::postorder(tree *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}

tree* tree::expression(char postfix[])
{
	int i=0;
	tree *ptr1, *ans;
	stack s;
	while(postfix[i]!='\0')
	{
		ptr1 = create(postfix[i]);
		if(isalnum(postfix[i]))
		{
			s.push(ptr1);	
		}
		else
		{
			ptr1->right=s.top->t;
			s.pop();
			ptr1->left=s.top->t;
			s.pop();
			s.push(ptr1);
		}
		i++;
	}
	ans = s.top->t;
	return ans;	
}

int main()
{
	tree t1;
	tree *t2;
	stack s1;
	char postfix[10];
	cout<<"Enter the Postfix Expression :";
	cin>>postfix;
	t2 = t1.expression(postfix);
	int c;
	do
	{
		cout<<"\n1]Inorder Recursive\n2]Inorder Non Recursive\n3]Preorder Recursive\n4]Preorder Non Recursive\n5]Postorder\n6]Exit\nEnter Your Choice :";
		cin>>c;
		switch(c)
		{
			case 1 : 
				cout<<"\nInorder Recursive : ";
				t1.inorder(t2);
				break;
			case 2 :
				cout<<"\nInorder Non Recursive : ";
				t1.ninorder(t2);
				break;
			case 3 :
				cout<<"\nPreorder Recursive : ";
				t1.preorder(t2);
				break;
			case 4 :
				cout<<"\nPreorder Non Recursive : ";
				t1.npreorder(t2);
				break;
			case 5 :
				cout<<"\nPostorder Recursive : ";
				t1.postorder(t2);
				break;
			case 6 : exit(0);
			default : cout<<"\nWrong Choice\n";
		}
	}while(c!=6);
}
