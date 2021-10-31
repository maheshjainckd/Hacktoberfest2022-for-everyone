// Note: For count sort, we're assuming the array elements in range [1, n)
// if no range is given, then first find the largest element k
// Make count_array[k+1];


// Sample Input: 
// 10
// 1 3 5 5 1 2 4 6 2 8
#include <iostream>
using namespace std;

void count_sort(int arr[], int n);

int main(){
	int n; 
    cout << "Enter array size: "; cin >> n;
    int arr[n];
    cout << "Enter array values: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    count_sort(arr, n);
    
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;

}
void count_sort(int arr[], int n){
	// Count Array
	int count_array[n] = {0};
	for (int i = 0; i < n; i++){
		count_array[arr[i]] += 1;
	}
	// Update the Count array values
	for (int i = 1; i < n; i++){
		count_array[i] += count_array[i-1];
	}
	// Put the Sorted Array in temp Array
	int temp[n];
	for (int i = n-1; i >= 0; i--){
		temp[--count_array[arr[i]]] = arr[i];
	}
	// Update our Initial Array
	for (int i = 0; i < n; i++){
		arr[i] = temp[i];
	}
}
