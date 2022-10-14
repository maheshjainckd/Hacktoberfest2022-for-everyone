// Array Intersection
#include<bits/stdc++.h>
void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Write your code here
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int i,j=0;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<endl;
}