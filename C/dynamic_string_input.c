#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	char c='a';
	char *ch = (char *) malloc (1*sizeof(char));
	int i=0;
	printf("\nEnter your string: ");
	while(c != '\r')
	{
		c = getche();

		if(c != '\r')
		{
			ch = (char *) realloc (ch,(i+1)*sizeof(char));
			ch[i++] = c;
		}
	}
	ch[i] = '\0';
	printf("\nEntered String: ");
	puts(ch);
	getch();
}
