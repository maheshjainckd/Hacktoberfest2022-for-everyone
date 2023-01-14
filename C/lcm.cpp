#include<stdio.h>
int main()
{
	 int a[3][3],i,j;
	 for(i=0;i<=2;i++)
	 {
	 	for(j=0;j<=2;j++)
	 	{
	 	scanf("%d",&a[i][j]);	
     	 }
	 }
	 
	 for(i=0;i<=2;i++)
	 {
	 int	s=0;
	 	for(j=0;j<=2;j++)
	 	{
	 	s=s+a[i][j];	
		}
	 }
	 printf("sum of the elemnts of the rows is =%d",s)
}
