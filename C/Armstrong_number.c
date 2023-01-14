#include<stdio.h>
void main()
{
 printf("enter the number=");    
scanf("%d",&n);
 armstrong(n);
}
 void armstrong(int n)    
{    
int r,sum=0,temp;        
temp=n;    
while(n>0)    
{    
r=n%10;    
sum=sum+(r*r*r);    
n=n/10;    
}    
if(temp==sum)    
printf("armstrong  number ");    
else    
printf("not armstrong number");    
return 0;  
} 
