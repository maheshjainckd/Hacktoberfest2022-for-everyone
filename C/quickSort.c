#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int x, int y)
{
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
}

void quick(int *a, int low, int high)
{
	if (low >= high)
		return;

	int mid = (low + high) / 2;
	swap(a, low, mid);
	int last = low;

	for (int i = low + 1; i < high; i++)
	{
		if (a[i] < a[low])
		{
			last = last + 1;
			swap(a, i, last);
		}
	}

	swap(a, low, last);
	quick(a, low, last - 1);
	quick(a, last + 1, high);
}

void main()
{
	int *a, i, n;
	printf("Enter n : ");
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	quick(a, 0, n);

	printf("Sorted Array : ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}

