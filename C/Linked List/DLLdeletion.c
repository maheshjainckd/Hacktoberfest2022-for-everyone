#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head,*newnode,*tail;

createDll()
{
    int choice=0;
    head=0;
    while(choice == 0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head == 0)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("enter 0 to add and 1 to exit: ");
        scanf("%d",&choice);
    }
}

del_at_beg()
{
    struct node *temp;
    if(head == 0)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
    }
}

del_at_end()
{
    struct node *temp;
    if(head == 0)
    {
        printf("List is empty");
    }
    else
    {
        temp=tail;
        tail->prev->next=0;
        tail=tail->prev;
        free(temp);
    }
}

del_at_pos()
{
    struct node *temp=head;
    int pos=0,i=1;
    printf("enter pos: ");
    scanf("%d",&pos);
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

display()
{
    struct node *temp;
    temp=head;
    printf("DLL is: ");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main()
{
    int a = 0;
    createDll();
    display();
    while (a < 5)
    {
        printf("1.beg\n2.end\n3.pos\n4.display\n5.exit");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            del_at_beg();
            break;

        case 2:
            del_at_end();
            break;

        case 3:
            del_at_pos();
            break;

        case 4:
            display();
            break;
        }
    }
}