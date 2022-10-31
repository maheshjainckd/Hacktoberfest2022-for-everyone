#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node * left;
    struct node * right;
    struct node * next;
} node;

node * createNode(char data){
    node * new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->next = NULL;

    return new;
}

node * head = NULL;

void inOrder(node * root){
    if(root != NULL){
        inOrder(root->left);
        printf("%c ",root->data);
        inOrder(root->right);
    }
}

void preOrder(node * root){
    if(root != NULL){
        printf("%c ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node * root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ",root->data);
    }
}

void push(node * x){
    if(head == NULL)
        head = x;
    else{
        x->next = head;
        head = x;
    }
}

node * pop(){
    node * p = head;
    head = head->next;
    return p;
}

void main(){
    char * s;
    printf("Enter the postfix expression: ");
    scanf("%s",s);
    int n = sizeof(s) / sizeof(s[0]);
    node *x, *y, *z;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
            z = createNode(s[i]);
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);
        }
        else{
            z = createNode(s[i]);
            push(z);
        }
        i++;
    }
    printf("Inorder Travesral: ");
    inOrder(z);
    printf("\n");
    printf("Preorder Traversal: ");
    preOrder(z);
    printf("\n");
    printf("Postorder Traversal: ");
    postOrder(z);
    printf("\n");
}