Skip to content
Search or jump to…
Pull requests
Issues
Marketplace
Explore
 
@TanishqKhetan 
loveBabbar
/
CodeHelp-DSA-Busted-Series
Public
Code
Issues
28
Pull requests
129
Actions
Projects
Security
Insights
CodeHelp-DSA-Busted-Series/Lecture046 Linked List Day3/reverseInKGroup.cpp

Love Babbar Adding codes for previous Lectures
Latest commit f26a642 on 16 Feb
 History
 0 contributors
46 lines (38 sloc)  947 Bytes

/****************************************************************
    Following is the Linked List node structure
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/


Node* kReverse(Node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
CodeHelp-DSA-Busted-Series/reverseInKGroup.cpp at main · loveBabbar/CodeHelp-DSA-Busted-Series
