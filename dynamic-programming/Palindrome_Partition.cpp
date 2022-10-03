// https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalindrome(s, i ,j)) return 0;
        
        int ans=INT_MAX; // how many partition in interval i to j
        for(int k=i; k<j; k++){
            if(isPalindrome(s,i,k)){
                int temp = 1 + solve(s,k+1,j);
                ans=min(ans,temp);
            }
        }
        return  dp[i][j]=ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
};