//author:Ujjwal Raj
    int A[100100];
    long long dp[100100];
    int done[100100];
    long long rec(int level){
        if(level<0)return 0;
        if(done[level])return dp[level];
        long long ans=max(rec(level-1)+A[level],1ll*A[level]);
        done[level]=1;
        return dp[level]=ans;
    }
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        for(int i=0;i<n;i++){
            A[i]=arr[i];
            done[i]=0;
        }
        long long ans=-1e15;
        for(int i=0;i<n;i++){
            ans=max(ans,rec(i));
        }
        return ans;
        
    }
