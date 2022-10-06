/*linear serch:
time complexity
best O(1);
worst O(n);
disadvantage: does not work in large array;
*/
#include<iostream>
using namespace std;

int main()
{
    int n,k,flag=1,i=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[n];
    }
    cin>>k;
    for(i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        cout<<"element not found";
    else
        cout<<"found at"<<i+1;



}
