#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail, *newnode;

createCll()
{
    int choice = 0;
    head = 0;
    while (choice == 0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next=head;
        printf("if want to continue press 0 to exit press 1: ");
        scanf("%d", &choice);
    }
}

insert_at_beg()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&newnode->data);
    if(tail == 0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }
    head=newnode;
}

insert_at_end()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&newnode->data);
    if(tail == 0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;    
    }
}

insert_at_pos()
{
    struct node *temp;
    int length=get_length(), pos=0, i = 1;
    temp = tail->next;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data and pos: ");
    scanf("%d %d", &newnode->data, &pos);
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
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

reverse_the_list()
{
    struct node *prevnode,*currnode,*nextnode;
    currnode=tail->next;
    nextnode=currnode->next;
    if(tail==0)
    {
        printf("List is empty");
    }
    else if(currnode->next==currnode)
    {
        printf("only one node present");
    }
    else
    {
        while(currnode!=tail)
        {
            prevnode=currnode;
            currnode=nextnode;
            nextnode=currnode->next;
            currnode->next=prevnode;
        }
        nextnode->next=tail;
        tail=nextnode;
    }

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

display()
{
    struct node *temp;
    temp = head;
    printf("CLL is : ");
    while (temp->next != head)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" %d ", temp->data);
    printf("\n");
}

void main()
{
    int a=0;
    createCll();
    display();
    while(a<6)
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