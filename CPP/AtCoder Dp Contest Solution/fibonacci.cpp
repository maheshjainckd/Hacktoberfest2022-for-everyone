#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int dp[100];

int fibo(int n){
    if(dp[n]!=-1)return dp[n];
    return dp[n] = ((fibo(n-1)%M)+(fibo(n-2)%M))%M;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    dp[2] = 1;
    int n;
    cin >> n;
    cout<<fibo(n)<<endl;

    return 0;}