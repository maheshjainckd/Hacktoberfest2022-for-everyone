#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head, *newnode, *tail;

createDll()
{
    int choice = 0;
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

insert_at_beg()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

insert_at_end()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&newnode->data);
    tail->next=newnode;
    newnode->prev = tail;
    tail=newnode;
}

int get_length()
{
    struct node *temp;
    int count=0,length=0;
    temp = head;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

insert_at_pos()
{
    struct node *temp;
    temp=head;
    int length = get_length();
    int pos,i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data and pos: ");
    scanf("%d %d",&newnode->data, &pos);
    if(pos<1 || pos > length)
    {
        printf("Invalid position!");
    }
    if(pos == 1)
    {
        insert_at_beg();
    }
    else
    {
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }
}

reverse_the_list()
{
    struct node *currnode,*nextnode;
    currnode=head;
    while(currnode!=0)
    {
        nextnode=currnode->next;
        currnode->next=currnode->prev;
        currnode->prev=nextnode;
        currnode=nextnode;
    }
    currnode = head;
    head=tail;
    tail=currnode;
}

display()
{
    struct node *temp;
    temp = head;
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
    while (a < 6)
    {
        printf("1.beg\n2.end\n3.pos\n4.rev\n5.display\n6.exit");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            insert_at_beg();
            break;

        case 2:
            insert_at_end();
            break;

        case 3:
            insert_at_pos();
            break;

        case 4:
            reverse_the_list();
            break;

        case 5:
            display();
            break;
        }
    }
}
