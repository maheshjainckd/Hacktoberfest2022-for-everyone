#include<stdio.h>
int main(){
    int fibo(int n);
    int n,f,i;
    printf("Enter No. of Terms\n");
    scanf("%d",&n);
    printf("Fibonacci Series-\n");
    for(i=1;i<=n;i++){
        f=fibo(i);
        printf("%d,",f);
    }
    return 0;
}
int fibo(int n){
    int f;
    if(n==1){
    return 0;}
    else if(n==2){
    return 1;}
    else {return f=fibo(n-1)+fibo(n-2);}
}
