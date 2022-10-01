#include<iostream>
using namespace std;
int main(){

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++){

    cin>>arr[i];
    }

int ans=2;
int d = a[1]-a[0];
int j= 2;
int curr = 2;
while (j<n)
{
    if(a[j]-a[j-1]  == d ){

        curr++;

    }
    else{

        d=a[j]-a[j-1];
        curr=2;
    }
    ans = max (ans,curr);
    j++;
}
cout<<ans<<endl;

return 0;
}su