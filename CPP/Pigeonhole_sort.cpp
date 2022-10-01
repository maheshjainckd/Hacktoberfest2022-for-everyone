/* C program to implement Pigeonhole Sort */
#include <bits/stdc++.h>
using namespace std;

/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int arr[], int n)
{
	// Find minimum and maximum values in arr[]
	int min = arr[0], max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int range = max - min + 1; // Find range

	// Create an array of vectors. Size of array
	// range. Each vector represents a hole that
	// is going to contain matching elements.
	vector<int> holes[range];

	// Traverse through input array and put every
	// element in its respective hole
	for (int i = 0; i < n; i++)
		holes[arr[i]-min].push_back(arr[i]);

	// Traverse through all holes one by one. For
	// every hole, take its elements and put in
	// array.
	int index = 0; // index in sorted array
	for (int i = 0; i < range; i++)
	{
	vector<int>::iterator it;
	for (it = holes[i].begin(); it != holes[i].end(); ++it)
			arr[index++] = *it;
	}
}

// Driver program to test the above function
int main()
{
	int arr[] = {8, 3, 2, 7, 4, 6, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	pigeonholeSort(arr, n);

	printf("Sorted order is : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
//ALGORITHM

/*Begin
   find max and min from the array list
   holeRange := max – min +1
   define holeRange number of Lists

   for i := 0 to n-1 do
      hole[array[i]-min].append(array[i])
   done

   count := 0
   for j := 0 to holeRange-1 do
      while hole[j] is not empty do
         array[count] := get first node of hole[j] and delete it
         count := count +1
      done
   done
End*/

// CODE
#include<iostream>
#include<list>
#include<cmath>
using namespace std;

void getMaxMin(int *arr, int n, int &maximum, int &minimum) {
   maximum = minimum = arr[0]; //initially max and min ar arr[0]

   for(int i = 1; i<n; i++) {
      if(arr[i] > maximum)
         maximum = arr[i]; //get maximum data
      if(arr[i] < minimum)
         minimum = arr[i]; //get minimum data
   }
}

void pegionHoleSort(int *arr, int n) {
   int max, min;
   getMaxMin(arr, n, max, min);
   int holeRange = max - min +1;
   list<int> hole[holeRange]; //create an array of holes

   for(int i = 0; i<n; i++) {
      hole[arr[i]-min].push_back(arr[i]);
   }

   int count = 0;
   for(int j = 0; j<holeRange; j++) {
      //delete from linked lists and store to array
      while(!hole[j].empty()) {
         arr[count] = *(hole[j].begin());
         hole[j].erase(hole[j].begin());
         count++;
      }
   }
}

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n]; //create an array with given number of elements
   cout << "Enter elements:" << endl;

   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }

   cout << "Data before Sorting: ";
   display(arr, n);
   pegionHoleSort(arr, n);
   cout << "Data after Sorting: ";
   display(arr, n);
}
