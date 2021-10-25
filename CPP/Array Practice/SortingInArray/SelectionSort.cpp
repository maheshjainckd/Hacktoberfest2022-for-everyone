#include <iostream>
using namespace std;

int main()
{
    //Taking input from the user.. 
    //Asking array size from the user
    int n;
    cout<<"Enter array size : ";
    cin>>n;

    int arr[n]; //Declared an array of size n..
    cout<<"Enter elements : ";
    for (int i=0;i<n;i++) //To take the input of the array elements I have used for loop..
    {
        cin>>arr[i];
    } 

    for (int i = 0; i < n - 1; i++) //This for loop will run from 0 to n-1..
    {
        for (int j = i + 1; j < n; j++) //This for loop will run from i+1 to n..
        {
            if (arr[j] < arr[i]) //If array of j (arr[j]) is less than array of i (arr[i])..
            {
                int temp = arr[j]; //I have maked a temp variable and store the value of array of j arr[j]..
                arr[j] = arr[i]; //Putted array of i (arr[i]) value in array of j (arr[j])..
                arr[i] = temp; //Putted temp in array of i (arr[i])..
            }
        }
    }

    //Used a for loop to print the sorted array..
    cout<<"Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}