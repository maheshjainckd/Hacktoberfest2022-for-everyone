// Finding peak element in a 2D Array.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Function to find the maximum in column 'mid'
// 'rows' is number of rows.
int findMax(int arr[][MAX], int rows, int mid, int& max)
{
	int max_index = 0;
	for (int i = 0; i < rows; i++) {
		if (max < arr[i][mid]) {
			// Saving global maximum and its index
			// to check its neighbours
			max = arr[i][mid];
			max_index = i;
		}
	}
	return max_index;
}

// Function to find a peak element
int findPeakRec(int arr[][MAX], int rows, int columns,
				int mid)
{
	// Evaluating maximum of mid column. Note max is
	// passed by reference.
	int max = 0;
	int max_index = findMax(arr, rows, mid, max);

	// If we are on the first or last column,
	// max is a peak
	if (mid == 0 || mid == columns - 1)
		return max;

	// If mid column maximum is also peak
	if (max >= arr[max_index][mid - 1] && max >= arr[max_index][mid + 1])
		return max;

	// If max is less than its left
	if (max < arr[max_index][mid - 1])
		return findPeakRec(arr, rows, columns, mid - ceil((double)mid / 2));

	// If max is less than its left
	// if (max < arr[max_index][mid+1])
	return findPeakRec(arr, rows, columns, mid + ceil((double)mid / 2));
}

// A wrapper over findPeakRec()
int findPeak(int arr[][MAX], int rows, int columns)
{
	return findPeakRec(arr, rows, columns, columns / 2);
}

// Driver Code
int main()
{
	int arr[][MAX] = { { 10, 8, 10, 10 },
					{ 14, 13, 12, 11 },
					{ 15, 9, 11, 21 },
					{ 16, 17, 19, 20 } };

	// Number of Columns
	int rows = 4, columns = 4;
	cout << findPeak(arr, rows, columns);
	return 0;
}
