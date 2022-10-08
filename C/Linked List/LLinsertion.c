#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

createll()
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
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("if want to continue press 0 to exit press 1: ");
        scanf("%d", &choice);
    }
}

insert_at_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

insert_at_end()
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

insert_at_pos()
{
    temp = head;
    int pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data and pos: ");
    scanf("%d %d", &newnode->data, &pos);
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

display()
{
    temp = head;
    printf("LL is : ");
    while (temp != 0)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

reverse_the_list()
{
    struct node *prevnode, *nextnode, *currnode;
    prevnode = 0;
    currnode = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
    display();
}

void main()
{
    int a = 0;
    createll();
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
