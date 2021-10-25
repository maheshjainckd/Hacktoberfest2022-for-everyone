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

    int counter=1; //Declared a variable counter for iterations and the counter will start from 1..
    while(counter<n-1) //Taken a while loop where we will keep repeating the process until the counter is less than n-1..
    {
        for(int i=0;i<n-counter;i++) //If there is ith iteration then we will check till n-i..
        {
            if(arr[i]>arr[i+1]) //If array of i (arr[i]) is more than array of i+1 (arr[i+1])..
            {
                int temp=arr[i]; //I have maked a temp variable and store the value of array of i arr[i]..
                arr[i]=arr[i+1]; //Putted array of i (arr[i]) value in array of i+1 (arr[i+1])..
                arr[i+1]=temp; //Putted temp in array of i+1 (arr[i+1])..
            }
        }
        counter++; //This will move to next iteration after the for loop is over..
    }
    
    //Used a for loop to print the sorted array..
    cout<<"Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}