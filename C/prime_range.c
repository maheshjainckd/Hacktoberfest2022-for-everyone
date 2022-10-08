#include<stdio.h>
#include<math.h>

// C program to find and print out numbers between a lower limit and upper limit range
int main()
{
    int i,j,l,u,count;
    printf("Enter the lower limit=");
    scanf("%d",&l);
    printf("Enter the upper limit=");
    scanf("%d",&u);
    for(i=l;i<=u;i++)
    {
        // Flag variable to tell if i is prime or not
        count=0;

        for(j=2;j<=sqrt(i);j++)
	    {
            if(i%j==0)
            {
    	    	count++;
	    	    break;
		    }
	    }
      // count == 1 means i is a prime number
      // i != 1 because 1 is neither prime or composite
	    if(count==0 && i!=1)
	    printf("%d\n",i);
    }
    return 0;
}
