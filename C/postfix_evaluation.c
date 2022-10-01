// Postfix Evaluation
// Ex: 1 3 + => 1 + 3 => 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// initialization of global variables
#define size 100
int stack[size];
int top = -1;

void push(int x)
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
    }

    else
    {
        stack[++top] = x;
    }
}

int pop()
{
    if (top == -1)
    {
        return 0;
    }

    else
    {
        int ele;
        ele = stack[top--];
        return ele;
    }
}

int main()
{
    char arr[50];
    int i = 0, op1, op2;
    printf("Enter the Postfix expression\n");
    scanf("%s", arr);

    for (i = 0; arr[i] != '\0'; i++)
    {
        if (isdigit(arr[i]))
        {
            push(arr[i] - '0');
        }

        else
        {
            op2 = pop();
            op1 = pop();

            switch (arr[i])
            {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;

            case '/':
                push(op1 / op2);
                break;

            case '^':
                push(op1 ^ op2);
                break;

            default:
                printf("\nInvalid operation\n");
                break;
            }
        }
    }

    printf("\nThe result is %d", stack[top]);

    return 0;
}