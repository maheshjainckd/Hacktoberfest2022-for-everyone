int dp[201][201];
    int solve(int e,int f)
    {
        if(f==0 or f==1) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int mn=INT_MAX;
        int low,high;
        for(int k=1;k<=f;k++)
        {
            if(dp[e-1][k-1]!=-1)
            {
                low=dp[e-1][k-1];
            }
            else
            {
                low=solve(e-1,k-1);
                dp[e-1][k-1]=low;
            }
            if(dp[e][f-k]!=-1)
            {
                high=dp[e][f-k];
            }
            else
            {
                high=solve(e,f-k);
                dp[e][f-k]=high;
            }
            int temp = 1+max(low,high);
            mn=min(temp,mn);
        }
        return dp[e][f]=mn;
    }
    int eggDrop(int e, int f) 
    {
        for(int i=0;i<201;i++)
        {
            for(int j=0;j<201;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(e,f);
    }
