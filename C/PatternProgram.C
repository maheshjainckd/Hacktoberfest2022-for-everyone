#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int s,i,l,m=71,rev,tArr[6],flag=5;
    clrscr();
    for(s = 65;s<=71;s++){
	for(i=65;i<=71;i++)
	{
		if(i<=m)
		{
			printf("%c",i);
		}
		else
		{
			printf(" ");
		}
		if(i!=71)
		{
			tArr[flag]=i;
			flag--;
		}

	}

	for(l=0;l<6;l++)
	{
		if(tArr[l]<=m)
		{
			printf("%c",tArr[l]);
		}
		else
		{
			printf(" ");
		}
	}
	m--;
	printf("\n");
    }
}

