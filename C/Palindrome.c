#include<stdio.h>
int main(){
    printf("Enter a Number : ");
    int x;
    scanf("%d",&x);
    int temp = x;
    int rem,digit=0;
    while(temp!=0){
        rem = temp%10;
        digit=digit*10+rem;
        temp/=10;
    }
    if(x==digit){
        printf("Number %d is a Palindrome.\n",x);
    }else{
        printf("Number %d is not a Palindrome.\n",x);
    }
    return 0;
}