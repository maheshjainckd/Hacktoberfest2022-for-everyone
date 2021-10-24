#include <iostream>
using namespace std;

int BinarySearch(int arr[], int l, int r, int x)
{
    int result;

    while(r>=l)
    {
       int mid = l + (r-l)/2;
       if(x==arr[mid])
       {
        result = mid; 
        return result;
       }
       else if (x>arr[mid])
       {
           l = mid +1;
           result = BinarySearch(arr,l,r,x);
           return result;
       } 
       else if (x<arr[mid])
       {
           r = mid - 1;
           result = BinarySearch(arr,l,r,x);
           return result;
       } 
       else 
         return -1;
    }
}

int main()
{
int arr[] = {5,10,15,20,25,30,35};
int n = sizeof(arr) / sizeof(arr[0]);

cout<<"Enter the value to be searched"<<endl;

int x;
cin>>x;
 
int result;
int l,r;
result = BinarySearch(arr,0,n-1,x);
if(result== -1)
{
    cout<<"Not found"<< endl;
}
else{
    cout<<"index is at"<<"   " << result<<endl;
}

return 0;
}