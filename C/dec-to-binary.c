//NAme - Nishant Singh.

//program in C to convert decimal number to binary number using the function.
#include<stdio.h>
int binary(x){
    int c, i , a[10];
    for ( i = 0; x > 0; i++)
    {
        a[i] = x%2;
        x=x/2;
    }
    printf("\n Binary of given Number is = ");
    for (i = i-1; i >= 0; i--)
    {
        printf("%d",a[i]);
    }   
    return c;
}
int main(){
    int n;
    printf("Enter a Decimal Number : ");
    scanf("%d",&n); 
    binary(n);
    return 0;
}
