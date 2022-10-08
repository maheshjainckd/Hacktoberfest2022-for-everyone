#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

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
    while (i < pos)
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
    int pos, i = 0;
    struct node *nextnode;
    printf("enter pos: ");
    scanf("%d", &pos);
    temp = head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(temp);
}

reverse_the_list()
{
    struct node *prevnode,*nextnode,*currnode;
    prevnode=0;
    currnode=nextnode=head;
    while(nextnode!=0)
    {
        nextnode=nextnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    head=prevnode;
}

void main()
{
}