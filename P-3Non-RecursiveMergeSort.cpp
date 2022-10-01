#include <stdio.h>
#define MAX 20
void merge(int a[], int lp, int m, int up)
{
    int i = lp, j = m + 1, k = lp;
    int b[MAX];
    while (i <= m && j <= up)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for (; i <= m; i++)
        b[k++] = a[i];
    for (; j <= up; j++)
        b[k++] = a[j];
    for (i = lp; i <= up; i++)
        a[i] = b[i];
}
void mergesort(int a[], int n)
{
    for (int s = 1; s <= n-1; s*=2)
    {
        for (int i = 0; i < n; i += 2 * s)
        {
            int lp = i, up = i + ((2 * s) - 1);
            int m = (lp + up) / 2;
            if (up >= n)
            up = n - 1;
            merge(a, lp, m, up);
        }
    }
}

int main()
{
    int a[MAX],n;
    
    printf("Enter size of array:");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    scanf("%d\t",&a[i]);
    mergesort(a, n);
    printf("Sorted Array list using Non Recursive Merge Sort:\n");
    for (int i = 0; i < n; i++)
    printf("%d\t", a[i]);
    return 0;
}
