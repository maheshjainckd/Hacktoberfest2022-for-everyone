#include<stdio.h>
#include<math.h>
//Check whether it is an Armstrong number or not
int main()
{
    int original_Num,num, arm,sum=0, in,c=0;
    printf("Enter a Number: ");
    scanf("%d", &num);
    original_Num=in=num;
    do
    {
       c++;
        in=in/10; 
    } while(in>0);
    do
    {
        arm=num%10;
        sum=sum+(int)pow(arm,c);
        num=(int)num/10;
    } while (num>0);
    if(sum==original_Num)
    {printf("Armstrong Number");}
    else
    {printf("Not an armstrong number");}
    return 0;
    
}
