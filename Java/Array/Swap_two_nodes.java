#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *swapNodes(Node *head, int i, int j)
{
    if(i == j)
    {
        return head;
    }
    Node *currentNode = head, *prev = NULL;
    
    Node *firstNode = NULL, *secondNode = NULL, *firstNodePrev = NULL, *secondNodePrev = NULL;
    
    int pos = 0;
    
    while (currentNode != NULL)
    {
        if (pos == i)
        {
            firstNodePrev = prev;
            firstNode = currentNode;
        }
        else if (pos == j)
         {
            secondNodePrev = prev;
            secondNode = currentNode;
         }
         prev = currentNode;
         currentNode = currentNode->next;
         pos++;
    }
    if (firstNodePrev != NULL)
    {
        firstNodePrev->next = secondNode;
    }
    else
    {
        head = secondNode;
    }
    if (secondNodePrev != NULL)
    {
        secondNodePrev->next = firstNode;
    }
    else
    {
        head = firstNode;
    }
    Node *currentFirstNode = secondNode->next;
    secondNode->next = firstNode->next;
    firstNode->next = currentFirstNode;
    return head;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
