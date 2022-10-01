#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    int n;
    int arr1[n-1];
    int ans[n];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n-1; i++){
            cin>>arr1[i];
        }
        ans[1]=arr1[1];
        for(int i=1; i<=n-1; i++){
            
            if(arr1[i]==0){
                ans[i+1]=ans[i];
                
            }
            else if(arr1[i]==1){
                ans[i+1]=ans[i]+1;
                
                
            }
            else if(arr1[i]==2){
                ans[i+1]=ans[i]-1;
                
            }
        }
        for(int i=1; i<=n; i++){
            cout<<ans[i];
        }
        
    }

return 0;
}