/*
G - Longest Path  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
There is a directed graph G with N vertices and M edges. The vertices are numbered 1,2,…,N, and for each i (1≤i≤M), the i-th directed edge goes from Vertex x 
i
​
  to y 
i
​
 . G does not contain directed cycles.

Find the length of the longest directed path in G. Here, the length of a directed path is the number of edges in it.

Constraints
All values in input are integers.
2≤N≤10^5
1≤M≤10^5
1≤xi,yi≤N
All pairs (xi,yi) are distinct.
G does not contain directed cycles.
Input
Input is given from Standard Input in the following format:

N M
x1 y1
x2 y2
:
xM yM​
 
Output
Print the length of the longest directed path in G.
Sample Input 1 
Copy
4 5
1 2
1 3
3 2
2 4
3 4
Sample Output 1 
Copy
3
The red directed path in the following figure is the longest:
Sample Input 2 
Copy
6 3
2 3
4 5
5 6
Sample Output 2 
Copy
2
The red directed path in the following figure is the longest:
Sample Input 3 
Copy
5 8
5 3
2 3
2 4
5 2
5 1
1 4
4 3
1 3
Sample Output 3 
Copy
3
The red directed path in the following figure is one of the longest:
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deq graph[100];
int dp[100];

int solve(int start){
    int ans = 0;
    
    if(dp[start]!=-1)return dp[start];

    for(auto i : graph[start]){
        if(dp[i]!=-1){
            ans = max(ans, 1 + dp[i]);
        }
        else{
            ans = max(ans,1 + solve(i));
        }
    }
    return dp[start] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int N,M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int ans = 0;

    for(int i = 1; i <= N; i++){
        ans = max(ans,solve(i));
    }

    cout << ans;

    return 0;}