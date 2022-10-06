int dp[501][501];
    bool isPalindrome(string &s,int i,int j)
    {
        if(i==j) return true;
        if(i>j) return false;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int i,int j)
    {
        if(isPalindrome(s,i,j)) return 0;
        if(i>=j) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp = 1 + solve(s,i,k) + solve(s,k+1,j);
            if(temp<mn)
            {
                mn=temp;
            }
        }
        return dp[i][j]=mn;
    }
    int palindromicPartition(string str)
    {
        // code here
        for(int i=0;i<501;i++)
        {
            for(int j=0;j<501;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(str,0,str.size()-1);
        
    }
