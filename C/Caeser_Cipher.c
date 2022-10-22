#include<stdio.h>
#include<string.h>
void main()
{
    int k,n,i,c=0;
    char str[100],ch;
    printf("\n Enter the plain text: ");
    gets(str);
    printf(" Enter the cipher key: ");
    scanf("%d",&k);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        str[i]=toupper(str[i]);
        if(str[i]!=' ')
        {
            str[i]=str[i]-65;
            str[i]=((str[i]+k)%26) +65;
        }
    }
    printf(" Cipher Text: %s\n",str);
}