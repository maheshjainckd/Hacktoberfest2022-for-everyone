/**Longest Palindromic Substring
 
    * Given a string s, return the longest palindromic substring in s.
    * A string is called a palindrome string if the reverse of that string is the same as the original string.
    * Example 1:
        * Input: s = "babad"
        * Output: "bab"
    * Example 2:
        * Input: s = "cbbd"
        * Output: "bb"
**/ 
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> lps(n, vector<int>(n, 0));
    
    int start = 0, len = 1;
    
    for(int i = 0; i < n; i++)
        lps[i][i] = 1;
    
    for(int i = 0; i < n-1; i++) {
        if(s[i] == s[i+1]) {
            lps[i][i+1] = 1;
            if(len < 2) {
                len = 2;
                start = i;
            }
        }
    }
    
    for(int k = 3; k <= n; k++) {
        for(int i = 0; i <= n-k; i++) {
            int j = i+k-1;
            
            if(s[i] == s[j] and lps[i+1][j-1] == 1) {
                lps[i][j] = 1;
                
                if(len < k) {
                    start = i;
                    len = k;
                }
            }
        }
    }
    
    string res = "";
    for(int i = start; i < start+len; i++)
        res += s[i];
    
    return res;
}

int main() {
    string a = "babad";
    cout << longestPalindrome(a) << endl;
    string b = "cbbd";
    cout << longestPalindrome(b) << endl;

    return 0;
}
