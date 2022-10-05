#include<stdio.h>
int main() {
   int i;
   int j;
   int r;

   printf("Number of Rows - ");
   scanf("%d", &r);

   for (i = 1; i <= r; ++i)
   {
      for (j = 1; j <= i; ++j)
      {
         printf("* ");
      }
      printf("\n");
   }
   return 0;
}