#include<iostream>
using namespace std;

//Maked a function linearSearch which will return index of type int.. and in this function I will be sending array, array size, and the key which we have to find..
int linearSearch(int arr[], int n, int key)
{
    for (int i=0;i<n;i++) //Used a for loop which will traverse the elements..
    {
        if(arr[i]==key) //And check whether array of i (arr[i]) is equal to key..
        {
        return i; //If it is equal to key then return i (index).. 
    }
    }
    return -1; //And if its not then return -1..
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

    //Here I called the function linearSearch and passed array (arr), n (array size), and key..
    cout<<"The key is present on index no : " << linearSearch(arr,n,key)<<endl;
    return 0;
}