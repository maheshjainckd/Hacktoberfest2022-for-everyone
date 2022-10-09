#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev; // for pointing to the previous of the LinkedList
    Node *next; // for pointing to the next of the LinkedList.
};

class D_ListClass
{
private:
    Node *head = NULL;

public:
    void LinkList_Creation();                          // for creating the Doubly LinkedList
    void Traversal_and_Display_List_Both_Directions(); // for doing the traversal of the List in the both direction.
};

void D_ListClass ::LinkList_Creation()
{
    int number_required, data_req; // for asking the user that how many nodes does he want  to create.
    Node *prevLink = NULL;
    Node *nextLink = NULL;
    cout << "Enter the number of the Nodes for creating the Doubly Linked List :- ";
    cin >> number_required;
    for (int i = 0; i < number_required; i++)
    {
        Node *currentNode = new Node; // for dynamically allocating the memory in the heap.
        cout << "Enter the required Data for"
             << " " << i + 1 << " inserting into the Linked List :- ";
        cin >> data_req;
        currentNode->data = data_req;
        currentNode->next = NULL;
        currentNode->prev = NULL;
        if (head == NULL)
        {
            head = prevLink = nextLink = currentNode; // when the head point is pointing to the null parameter .
        }
        else
        {
            nextLink->next = currentNode;
            nextLink = currentNode;
            nextLink->prev = prevLink;
            prevLink = prevLink->next;
        }
    }
}

void D_ListClass ::Traversal_and_Display_List_Both_Directions()
{
    Node *ptr = head;
    cout << "Displaying the result in the forward Direction " << endl;
    cout << endl;
    while (ptr->next != NULL)
    {
        cout << ptr->data;
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            cout << "";
        }
        else
        {
            cout << ",";
        }
    }
    cout << "," << ptr->data;
    cout << endl;
    cout << "Displaying the result in the previous Direction " << endl;
    cout << endl;
    while (ptr->prev != NULL)
    {
        cout << ptr->data;
        ptr = ptr->prev;
        if (ptr->prev == NULL)
        {
            cout << "";
        }
        else
        {
            cout << ",";
        }
    }
    cout << "," << ptr->data;
    cout << endl;
}

int main()
{
    int choice;
    D_ListClass object;
    do
    {
        cout << "1. Create the Doubly Linked List" << endl;
        cout << "2. Traversal the list and Display in both the reverse and  the forward Direction" << endl;
        cout << "3. Exit";
        cout << endl;
        cout << "Enter your choice :- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            object.LinkList_Creation();
            break;
        case 2:
            object.Traversal_and_Display_List_Both_Directions();
            break;
        case 3:
            break;

        default:
            cout << "Wrong Choice Please Enter the choice Again !!!!!!!" << endl;
            break;
        }

    } while (choice != 3);
}