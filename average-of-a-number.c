#include<stdio.h>
int main()
{
int n,i=1,sum=0;
float avg=0.0;
printf("\nEnter the value of n:");
scanf("%d",&n);
do{
sum=sum+i;
i=i+1;
}
while(i<=n);
avg=(float)sum/n;
printf("The Sum of first %d numbers=%d",n,sum);
printf("\nThe average of first %d numbers=%0.2f",n,avg);
return 0;
}
