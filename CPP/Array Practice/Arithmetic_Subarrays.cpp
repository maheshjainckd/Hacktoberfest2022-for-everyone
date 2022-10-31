#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int curr=2;
    int ans=2;
    int pd=arr[1]-arr[0];
    int j=0;
    while(j<n)
    {
        if(pd==arr[j+1]-arr[j])
        {
            curr++;
        }
        else{
            pd=arr[j+1]-arr[j];
            curr=2;
        }
        ans=max(ans,curr);
        j++;

    }
    cout<<ans;
    return 0;
}

