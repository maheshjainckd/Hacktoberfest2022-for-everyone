#include<bits/stdc++.h>
using namespace std;
void swap(int *a ,int *b)
{
    int *temp ;
    *temp = *a;
    *a=*b;
    *b=*temp;
}
void waveSort(int arr[],int n)
{
    sort(arr,arr+n);
    for(int i=0;i<n-1;i+=2)
    swap(&arr[i],&arr[i+1]);

}
int main()
{
    int arr[]={10,5,6,3,2,20,100,80};
    int n= sizeof(arr)/sizeof(arr[0]);
     waveSort(arr,n);
     for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
}
