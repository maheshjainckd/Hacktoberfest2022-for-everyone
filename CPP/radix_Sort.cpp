#include<bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[],int n,int pos){
     int count[20]={};
     int b[n];
     for(int i=0;i<n;i++){
          count[(arr[i]/pos)%10]++;
     }
     for(int i=1;i<10;i++){
          count[i]=count[i]+count[i-1];
     }
     for(int i=n-1;i>=0;i--){
          b[--count[(arr[i]/pos)%10]]=arr[i];
     }
     for(int i=0;i<n;i++){
       arr[i]=b[i];
     }
}

void radixSort(int arr[],int n){
    int max1=getMax(arr,n);
    for(int pos=1;max1/pos>0;pos*=10){
      countSort(arr,n,pos);
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
      radixSort(arr, n);
    print(arr, n);
    return 0;
}
