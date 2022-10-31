// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.

// For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
// 2+2+5
// 3+3+3
// 2+2+2+3

#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
  
    int n,x;
    cin>>n>>x;
    int c[n];
    int mod = 1e9+7;
    for(int i=0;i<n;i++)
    {
      cin>>c[i];
    }
    int dp[n+1][x+1];
    for(int r=0;r<=n;r++)
    {
      for(int j=0;j<=x;j++)
      {
        
        dp[r][j]=0;
      }
    }
    dp[0][0]=1;
    for(int r=1;r<=n;r++)
    {
      for(int j=0;j<=x;j++)
      {
        dp[r][j]=dp[r-1][j];
        if (j-c[r-1]>=0)
        (dp[r][j]+=dp[r][j-c[r-1]])%=mod;
      }
    }
    cout<<dp[n][x];
    return 0;
}
