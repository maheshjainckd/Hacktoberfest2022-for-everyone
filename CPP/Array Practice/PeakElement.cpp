#include <iostream>
using namespace std;

// Here low and high will decide start and end of binary search range..
int findPeakElement(int arr[], int low, int high, int n)
{
    //Formula to find mid..
    int mid = low + (high - low) / 2;
    //So.. first we will check whether the mid index value is peak element or not..
    if (
        (mid == 0) || arr[mid - 1] <= arr[mid] && (mid == n - 1) || arr[mid + 1] <= arr[mid])
    {
        return mid;
    }
    //If its not.. then we will take two condions..
    else if (mid > 0 && arr[mid - 1] > arr[mid])
    {
        return findPeakElement(arr, low, mid - 1, n); //First.. In this case.. We will return whatever will come from the left half of the array.. basically we will search the left half of the array..
    }
    else
    {
        return findPeakElement(arr, mid + 1, high, n); //Second.. In this case.. We will return whatever will come from the right half of the array.. basically we will search the right half of the array..
    }
}
//So once we've got the peak element.. we will print the index of the peak element which we've got..
int main()
{
    int arr[] = {0, 5, 10, 8, 7, 6}; //I have defined an array and initialized some elements in it..
    int n = 5; //I have taken n as 5..
    cout << "Peak Element Index is : " << findPeakElement(arr, 0, n - 1, n) << endl; //I have called findPeakElement function and passed array, low as 0 and high as n-1..
    return 0;
}
