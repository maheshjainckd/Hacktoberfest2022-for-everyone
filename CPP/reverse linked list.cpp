#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insert(node **head, int data)
{
    node *newnode = (node *)malloc(1 * sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if ((*head) == NULL)
    {
        (*head) = newnode;
        return;
    }
    node *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void reverselinked(node *head)
{
    node *prev = NULL;
    node *current = head;
    while (current != NULL)
    {
        node *nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    node *ptr = prev;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
}

int main()
{
    node *start = NULL;
    int n, data;
    cin >> n;
    while (n--)
    {
        cin >> data;
        insert(&start, data);
    }
    reverselinked(start);
}
