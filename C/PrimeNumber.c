#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num <= 0)
    {
        printf("The number should be positive!\n");

        printf("\nEnter an integer: ");
        scanf("%d", &num);
    }

    if (num == 1)
    {
        printf("%d is not a prime number.\n", num);
    }

    else if (num <= 3)
    {
        printf("%d is a prime number.\n", num);
    }

    else
    {
        if (num % 2 == 0)
        {
            printf("%d is not a prime number.\n", num);
        }

        else
        {
            for (int i = 3; i <= num / 2; i++)
            {
                if (num % i == 0)
                {
                    printf("%d is not a prime number.\n", num);

                    count++;

                    break;
                }
            }

            if (count == 0)
            {
                printf("%d is a prime number.\n", num);
            }
        }
    }

    return 0;
}
