#include <bits/stdc++.h>
using namespace std;
int dp[100][1000];

knapsnap(int len[],int val[],int n,int N){
    if(n==0 || N<=0){
        return 0;
    }

    if (dp[n][N]!=-1){
        return dp[n][N];
    }

    if(len[n-1]<=N){
        return dp[n][N]=max(knapsnap(len,val,n-1,N),knapsnap(len,val,n,N-len[n-1])+val[n-1]);
        //here n-1 will be changed with n remaining code remain same thats 0-1 knapsack converted into unbound knapsack
    }
    else
    return dp[n][N]=knapsnap(len,val,n-1,N);

}
int main()
{
    memset(dp,-1,sizeof(dp));
    int len[8]={1,2,3,4,5,6,7,8};
    int val[8]={1,5,8,9,10,17,17,20};
    int N=8;
    cout<<knapsnap(len,val,8,N);

}