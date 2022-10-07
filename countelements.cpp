#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int cnt=0,cnt1=0,n;
    int arr[n],x;
    vector<int> vec(n,0);
    cin>>n>>x;
    //O(n)

    for(int k=0;k<n;k++)
        {
            cin>>arr[k];
            cin>>vec[k];
        } 
    for(int i=0;i<n;i++)
        {
            if(arr[i]==x && vec[i]==x)
            {
                cnt++;
                cnt1++;
            }
        }

    cout<<cnt<<"   "<<cnt1;


    //count in one line
    //O(N) times
    //count(start_iterator, end_iterator, element to be counted)
    // int cnt=count(arr,arr+n,1);
    // int cnt=count(vec.begin(),vec.end(),1);
    return 0;
}
