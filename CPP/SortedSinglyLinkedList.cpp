#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
}*p = NULL, *head = NULL, *q = NULL, *np = NULL;
int c = 0;
void create(int x)
{
    np = new node;
    np->data = x;
    np->next = NULL;
    if (c == 0)
    {
        head = np;
        p = head;
        p->next = head;
        c++;
    }
    else if (c == 1)
    {
        p = head;
        q = p;
        if (np->data < p->data)
        {
            np->next = p;
            head = np;
            p->next = np;
        }
        else if (np->data > p->data)
        {
            p->next = np;
            np->next = head;
        }
        c++;
    }
    else
    {
        p = head;
        q = p;
        if (np->data < p->data)
        {
            np->next = p;
            head = np;
            do
            {
                p = p->next;
            }
            while (p->next != q);
            p->next=head;
        }
        else if (np->data > p->data)
        {
            while (p->next !=head && q->data < np->data)
            {
                q = p;
                p = p->next;
                if (p->next == head  && (p->data < np->data))
                {
                    p->next = np;
                    np->next = head;
                }
                else if (np->data < p->data)
                { 
                    q->next = np;
                    np->next = p;
                    break;
                }
            }
        }
    }
}
void traverse(int i)
{
    node *t = head;
    int c = 0;
    while (c <= i)
    {
        cout<<t->data<<"\t";
        t = t->next;
        c++;
    }
}
int main()
{
    int i = 0, n, x;
    cout<<"enter the no of nodes\n";
    cin>>n;
    while (i < n)
    {
        cout<<"\nenter value of node\n";
        cin>>x;
        create(x);
        i++;
    }
    cout<<"\n\nlinear display of nodes currently present in circularly linked list....\n\n";
    traverse(n);
    getch();
}