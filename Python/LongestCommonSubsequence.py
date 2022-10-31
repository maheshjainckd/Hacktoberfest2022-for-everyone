//LEETCODE-1143. Longest Common Subsequence
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for i in range(len(text2)+1)] for j in range(len(text1)+1)]
        
        n = len(text1)
        m = len(text2)
        for i in range(n+1):
            dp[i][0] = 0
        for i in range(m+1):
            dp[0][i] = 0
        
        for i in range(1,n+1):
            for j in range(1,m+1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = 1+dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                    
        # print(dp)
        return dp[n][m]
