/*
LCS 
You are given strings s and t. Find one longest string that is a subsequence of both s and t.
Notes
A subsequence of a string x is the string obtained by removing zero or more characters from x and concatenating the remaining characters without changing the order.

Constraints
s and t are strings consisting of lowercase English letters.
1≤∣s∣,∣t∣≤3000
Input
Input is given from Standard Input in the following format:

s
t
Output
Print one longest string that is a subsequence of both s and t. If there are multiple such strings, any of them will be accepted.

Sample Input 1 
Copy
axyb
abyxb
Sample Output 1 
Copy
axb
The answer is axb or ayb; either will be accepted.

Sample Input 2 
Copy
aa
xayaz
Sample Output 2 
Copy
aa
Sample Input 3 
Copy
a
z
Sample Output 3 
Copy
The answer is (an empty string).

Sample Input 4 
Copy
abracadabra
avadakedavra
Sample Output 4 
Copy
aaadara
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

string a,b;
deque<string> answers;
bool check[100][100];
string dp[100][100];

string solve(int na,int nb){
    if(na<0 || nb<0)return "";
    if(check[na][nb])return dp[na][nb];
    string ans = "";
    string z = "";
    if(a[na]==b[nb]){
        ans = solve(na-1,nb-1) + a[na];
    }
    z = solve(na,nb-1);
    ans = ans.size()>=z.size() ? ans : z; 
    z = solve(na-1,nb); 
    ans = ans.size()>=z.size() ? ans : z;
    check[na][nb] = true;
    return dp[na][nb] = ans; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    string ans = solve(a.size()-1,b.size()-1);
    cout<<ans;

    return 0;}