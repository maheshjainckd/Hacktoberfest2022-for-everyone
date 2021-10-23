/*
Kth divisibility Reverse 

INPUT 
9 3 

5 2 7 9 4 1 3 8 6


OUTPUT
7 2 5 1 4 9 6 8 3 


EXPLAINATION
here n is 9 and k is 3 
so linked list is divided into sublinked list of size 3 
ie. 3 linked list of size 3 
and reversal of these 3 linked list is done

5 2 7 --> 7 2 5
9 4 1 --> 1 4 9
3 8 6 --> 6 8 3


*/

#include <iostream>

using namespace std;


class node
{
    
    public:
    
    int data;
    node* next;
    
};


void createLinkList(node* &head, int num)
{
    node* temp = NULL;
    
    for(int i = 0; i < num; i++)
    {
        node* new_node = new node();
        
        cin >> new_node -> data;
        
        new_node -> next = NULL;
        
        
        if(head == NULL)
        {
            head = new_node;
            temp = head;
        }
        
        else
        {
            temp -> next = new_node;
            temp = new_node;
        }
        
    }
    
    
}


void print(node* head)
{
    
    node* temp = head;
    
    while(temp!=NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    cout << endl;
}

/*
void reverse(node* &head)
{
    node* current = head;
    node* prev = NULL;
    node* next = NULL;
    
    while(current!=NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
        
    }
    
    head = prev;
}
*/


// reverse when divisible by k 
node *reverse (node *head, int k)
    { 
        // Complete this method
        if(head == NULL)
        {
            return NULL;
        }
        
        node* curr = head;
        node* prev = NULL;
        node* next = NULL;
        
        int cnt = 0;
        
        while(curr != NULL && cnt < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        if(next != NULL)
        // last element nhi hai 
        {
            head->next = reverse(next,k);
        }
        
        return prev;
    }



int main()
{
    node* head = NULL;
    
    int n;
    int k;
    cin >> n >>k;
    
    createLinkList(head, n);
    
    // print(head);
    
    node* answer = reverse(head,k);
    
    print(answer);

    return 0;
}


/*

OUTPUT

9 3
5 2 7 9 4 1 3 8 6
7 2 5 1 4 9 6 8 3 

*/
