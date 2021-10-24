#include<iostream>
using namespace std;

//Maked a function binarySearch which will return index of type int.. and in this function I will be sending array, array size, and the key which we have to find..
int binarySearch(int arr[], int n, int key)
{
    int Start=0; //Defined the starting point of the array as 0..
    int End=n; //Defined the ending point of the array as n..
    while(Start<=End) //Whatever work we will do we will do it until Start is less than equal to End (Start<=End)
    {
        int mid=(Start+End)/2; //To find mid.. (With this we can get the index of the mid element..)
        if (arr[mid]==key) //Comparing mid element with the key..
        {
            return mid; //If mid is equal to key then return mid..
        }
        else if (arr[mid]>key) //Here key is less than mid.. (It means that the key is present on the first half..)
        {
            End=mid-1; //If it is then shift 'End' to 'mid-1'.. 
        }
        else
        {
            Start=mid+1; //Else shift 'Start' to 'mid+1'..
        }
        return -1; //If key is not present on the array then return -1..
    }
}
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
    
    //Taking input of the key which we have to find..
    int key;
    cout<<"Enter key to find : ";
    cin>>key;

    //Here I called the function binarySearch and passed array (arr), n (array size), and key..
    cout<<"The key is present on index no : " << binarySearch(arr,n,key)<<endl;
    return 0;
}