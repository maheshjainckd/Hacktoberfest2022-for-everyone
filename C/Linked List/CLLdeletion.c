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
        printf("if want to continue press 0 to exit press 1: ");
        scanf("%d", &choice);
    }
}

del_at_beg()
{
    struct node *temp;
    temp = tail->next;
    if (tail == 0)
    {
        printf("list is empty");
    }
    else if (temp == tail || temp->next == temp)
    {
        tail = 0;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}

del_at_end()
{
    struct node *curr, *prev;
    curr = tail->next;
    if (tail == 0)
    {
        printf("list is empty");
    }
    else if (curr == tail || curr->next == curr)
    {
        tail = 0;
        free(curr);
    }
    else
    {
        while (curr->next != tail->next)
        {
            prev = curr;
            curr = curr->next;
            prev->next = curr->next;
            tail = prev;
            free(curr);
        }
    }
}

del_at_pos()
{
    int length=get_length(),pos, i = 1;
    struct node *curr, *nextnode;
    curr = tail->next;
    printf("enter pos: ");
    scanf("%d", &pos);
    if(pos<1 || pos > length)
    {
        printf("Invalid position!");
    }
    if(pos == 1)
    {
        del_at_beg();
    }
    else
    {    
        while (i < pos - 1)
        {
            curr = curr->next;
            i++;
        }
        nextnode = curr->next;
        curr->next = nextnode->next;
        free(nextnode);
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
    createCll();
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