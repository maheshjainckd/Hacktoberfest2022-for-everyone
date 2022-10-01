/*
A - Frog 1
Problem Statement
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi.

There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to Stone any of i+1 or i+2. Here, a cost of (hi − hj) is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints
All values in input are integers.
2≤N≤10 
5
 
1≤hi≤10^4
 
Input
N K
h1 h2 … hN
​ 
Output
Print the minimum possible total cost incurred.

Sample Input 1 
Copy
4
10 30 40 20
Sample Output 1 
Copy
30
If we follow the path 1 → 2 → 4, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Sample Input 2 
Copy
2
10 10
Sample Output 2 
Copy
0
If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.

Sample Input 3 
Copy
6
30 10 60 10 60 50
Sample Output 3 
Copy
40
If we follow the path 1 → 3 → 5 → 6, the total cost incurred would be ∣30−60∣+∣60−60∣+∣60−50∣=40.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int h[1000];
int dp[1000];
deq costs;

// TOP TO BOTTOM DYNAMIC PROGRAM

// int min_cost(int n){
//     if(n<1) return M;
//     if(n==1)return 0;
//     if(dp[n]!=-1)return dp[n];
//     return dp[n] = min(abs(h[n]-h[n-1])+min_cost(n-1),abs(h[n]-h[n-2])+min_cost(n-2));
// }

// RECURSION AND BACKTRACKING

// void min_cost(int start, int end,int cost){
//     if(start > end)return;
//     if(start == end){costs.push_back(cost);return;}
//     cost += abs(h[start+1]-h[start]);
//     min_cost(start+1, end, cost);
//     cost -= abs(h[start+1]-h[start]);
//     cost += abs(h[start+2]-h[start]);
//     min_cost(start+2, end, cost);
// }

// BOTTOM TO TOP

// int min_cost(int n,int target){
//   if(n>target)return M;
//   if(n == target)return 0;
//   if(dp[n]!=-1)return dp[n];
//   return dp[n] = min(abs(h[n]-h[n+1])+min_cost(n+1,target),abs(h[n+2]-h[n])+min_cost(n+2,target));
// }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    // cout<<min_cost(n);
    // sort(costs.begin(),costs.end());
    // cout<<costs[0];
    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);

    for(int i = 3; i<=n;i++){
      dp[i] = min(dp[i-2]+abs(h[i]-h[i-2]),dp[i-1]+abs(h[i]-h[i-1]));
    }
    cout<<dp[n];

    return 0;}