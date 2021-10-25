#include<iostream>
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

    for(int i=1;i<n;i++) //Taken a for loop which will start from 1 and will run till n.. 
    {
    int current = arr[i]; //I have maked a separate variable 'current' for current in which I have given array of i (arr[i])..
    int j=i-1; //Maked an another variable j which will start from i-1..
    while(arr[j]>current && j>=0) //If array of j (arr[j]) is more than current.. And j should be more than equal to 0 ( Making sure that when we are doing j--, the j should not go less than 0 so that's why I have taken the condition j should be more than equal to (j>=0).. )
    {
    arr[j+1]=arr[j]; //Then move one position ahead..
    j--; //Then go to previous element..
    }
    arr[j+1]=current; //Then add 'current' to one postion ahead of j.. ( Because after the loop j-- would have happened so we have to add the 'current' one position ahead of j )
    }

    //Used a for loop to print the sorted array..
    cout<<"Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}