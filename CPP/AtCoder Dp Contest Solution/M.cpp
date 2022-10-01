/*
M - Candies

Problem Statement
There are N children, numbered 1,2,…,N.

They have decided to share K candies among themselves. Here, for each i (1≤i≤N), Child i must receive between 0 and ai candies (inclusive). Also, no candies should be left over.

Find the number of ways for them to share candies, modulo 10^9+7. Here, two ways are said to be different when there exists a child who receives a different number of candies.

Constraints
All values in input are integers.
1≤N≤100
0≤K≤10^5
0≤ai≤K
Input
Input is given from Standard Input in the following format:

N K
a1 a2 … aN
​
Output
Print the number of ways for the children to share candies, modulo 10^9+7.

Sample Input 1 
Copy
3 4
1 2 3
Sample Output 1 
Copy
5
There are five ways for the children to share candies, as follows:

(0,1,3)
(0,2,2)
(1,0,3)
(1,1,2)
(1,2,1)
Here, in each sequence, the i-th element represents the number of candies that Child i receives.

Sample Input 2 
Copy
1 10
9
Sample Output 2 
Copy
0
There may be no ways for the children to share candies.

Sample Input 3 
Copy
2 0
0 0
Sample Output 3 
Copy
1
There is one way for the children to share candies, as follows:

(0,0)
Sample Input 4 
Copy
4 100000
100000 100000 100000 100000
Sample Output 4 
Copy
665683269
Be sure to print the answer modulo 10^9+7.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int N;
ll dp[100][100007];
deq candies;

ll func(int k,int n){
    if(k == 0)return 1;
    if(n == N && k!=0)return 0;

    if(dp[n][k]!=-1)return (dp[n][k]%M);

    ll ways = 0;

    for(int i = 0 ; i <= candies[n] ; i++){
        if(i>k)break;
        ways = ((ways%M) + (func(k-i,n+1)%M))%M;
    }
    return dp[n][k] = (ways%M);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int k;
    cin >> N >> k;
    
    int x;

    for(int i = 0; i < N; i++){
        cin >> x;
        candies.push_back(x);
    }

    cout<<(func(k,0)%M);

    return 0;}