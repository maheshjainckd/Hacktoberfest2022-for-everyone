#include<stdio.h>

#define M 3
#define N 3

int binarySearch1D(int arr[], int K) 
{ 
    int low = 0; 
    int high = N - 1; 
    while (low <= high) { 
        int mid = low + (high - low) / 2;
        if (arr[mid] == K) 
            return 1;
        if (arr[mid] < K) 
            low = mid + 1; 
        else
            high = mid - 1; 
    } 
    return 0; 
}
int searchMatrix(int matrix[M][N], int K) 
{ 
    int low = 0; 
    int high = M - 1; 
    while (low <= high) { 
        int mid = low + (high - low) / 2; 
        if (K >= matrix[mid][0] 
            && K <= matrix[mid][N - 1]) 
            return binarySearch1D(matrix[mid], K); 
        if (K < matrix[mid][0]) 
            high = mid - 1; 
        else
            low = mid + 1; 
    } 
    return 0; 
} 
int main() 
{ 
	int i=0,j=0;
	int K=0;
	int matrix[M][N];
	printf("Enter the elements of the matrix row wise\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("Enter the No to be searched\n");
	scanf("%d",&K);
    if (searchMatrix(matrix, K)) 
        printf("Found\n");
    else
        printf("Not Found\n");
} 
