#include <iostream>
#include <climits> //I have mentioned this header file because below I have initialized my max and min no. with INT_MIN and INT_MAX..
using namespace std;

int main()
{
    //Taking input from the user..
    int n;
    cout<<"Enter array size = ";
    cin >> n;

    //I have made an array of size n and taken input from the user for all the elements in an array by applying for loop..
    int arr[n];
    cout<<"Enter elements = ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    //Here.. I have taken two variable and initialized it..
    int maxNo=INT_MIN; //I have taken INT_MIN for better upproach.. Basically INT_MIN is the minimum integer possible in C++..
    int minNo=INT_MAX; //I have taken INT_MAX for better upproach.. Basically INT_MAX is the maximum integer possible in C++..

    for(int i=0;i<n;i++) //This loop will run from 0 to n..
    {
        maxNo=max(maxNo,arr[i]); //I have used built-in function 'max' which will give maximum of those two numbers which we have provided.. So, it will compare the maxNo and arr[i] and after comparing, it will allocate the maximum value to maxNO..
        minNo=min(minNo,arr[i]); //I have used built-in function 'min' which will give minimum of those two numbers which we have provided.. So, it will compare the minNo and arr[i] and after comparing, it will allocate the minimum value to minNO..
    }

    //To print max and min no..
    cout<<"Max no. is = "<<maxNo<<" "<<endl<<"Min no. is = "<<minNo<<" "<<endl;
    return 0;
}