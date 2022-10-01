/*
A - Frog 1
Problem Statement
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi.

There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to Stone any of i+1,i+2,…,i+K. Here, a cost of (hi − hj) is incurred, where j is the stone to land on.
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
5 3
10 30 40 50 20
Sample Output 1 
Copy
30
If we follow the path 1 → 2 → 5, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Sample Input 2 
Copy
3 1
10 20 10
Sample Output 2 
Copy
20
If we follow the path 1 → 2 → 3, the total cost incurred would be ∣10−20∣+∣20−10∣=20.

Sample Input 3 
Copy
2 100
10 10
Sample Output 3 
Copy
0
If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.

Sample Input 4 
Copy
10 4
40 10 20 70 80 10 20 70 80 60
Sample Output 4 
Copy
40
If we follow the path 1 → 4 → 8 → 10, the total cost incurred would be ∣40−70∣+∣70−70∣+∣70−60∣=40.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int dp[1000];
int h[1000];

int func(int n,int k){
    
    if(n == 1)return 0;
    if(dp[n]!=-1)return dp[n];

    int cost = INT_MAX;

    for(int i = 1 ; i<=k; i++){
        if(n-i>=1){
            cost = min(cost,abs(h[n]-h[n-i]) + func(n-i,k));}
        else break;
    }
    
    return dp[n] = cost;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int n,k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }

    cout<<func(n,k);

    return 0;}