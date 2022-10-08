#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *temp, *newnode;

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

del_at_beg()
{
    temp = head;
    head = temp->next;
    free(temp);
}

del_at_end()
{
    struct node *prev;
    temp = head;
    while (temp->next != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = 0;
    free(temp);
}

del_at_pos()
{
    int pos, i = 1;
    struct node *nextnode;
    printf("enter pos: ");
    scanf("%d", &pos);
    temp = head;
    while (i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
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

void main()
{
    int a = 0;
    createll();
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