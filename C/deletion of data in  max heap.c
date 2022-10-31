#include <stdio.h>

void swap(int* a , int* b)
{
    int i;
    
    i = *a;
    *a = *b;
    *b = i;
}

void main()
{
    int a[9] = {3231,456,45,56,5,3,12,3,43};
    int i = 0;
   
    
    a[0] = a[8];
    
    while (a[i] < a[2 * i + 1] || a[i] < a[2 * i + 2] )
    {
        if (a[i] < a[2 * i + 1] && a[i] > a[2 * i + 2])
        {
            swap (&a[i] , &a[2 * i + 1]);
            i = 2 * i + 1;
        }
        if (a[i] < a[2 * i + 1] && a[i] < a[2 * i + 2])
        {
            if (a[2 * i + 1] > a[2 * i + 2])
            {
                swap (&a[i] , &a[2 * i + 1]);
                i = 2 * i + 1;
            }
            else
            {
                swap (&a[i], &a[2 * i + 2]);
                i = 2 * i + 2;
            }
        }
        if (2 * i + 1 > 7)
        {
            break;
        }
    
    }
    i = 0;
    
    for (i = 0 ; i <= 7 ; i++)
    {
        printf ("%d ", a[i]);
    }
}
