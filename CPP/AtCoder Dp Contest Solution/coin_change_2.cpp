/*
Coin Change 2

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1

Constraints:
1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

deq coins;
int dp[1000];
int n;

// int func(int amount,int index){
//     if(amount == 0) return 1;
//     if(index == n || amount < 0)return 0;
//     if(dp[amount][index]!=-1)return dp[amount][index];
//     int z = amount;
//     int ans = 0;
//     while(z >=0){
//         ans += func(z,index+1);
//             z -= coins[index];
//     }
//     return dp[amount][index] = ans;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // memset(dp,-1,sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }

    int amount;
    cin >> amount;

    sort(coins.begin(),coins.end());
    reverse(coins.begin(),coins.end());

    // cout << func(amount,0);
    dp[0] = 1;

    for(int i = 1; i <= amount; i++){
        for(int j = 0; j<n; j++){
            if(i<coins[j])break;
            int z = i;
            while(z>=coins[j]){
                z-=coins[j];
            dp[i]+=(dp[z]);}
        }
    }

    cout << dp[amount];

    return 0;}