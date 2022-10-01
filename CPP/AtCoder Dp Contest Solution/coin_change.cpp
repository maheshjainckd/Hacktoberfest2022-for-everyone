/*
Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
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
int n;
int dp[1000];

// int min_number_of_coins(int amount){
//     if(amount == 0)return 0;

//     if(dp[n]!=-1)return dp[n];

//     int ans = M;
//     for(auto i : coins){
//         if(amount - i >= 0){
//         ans = min(ans,1+min_number_of_coins(amount-i));}
//     }
    
//     return dp[n] = ans;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // memset(dp,-1, sizeof(dp));

    int amount;
    cin >> n;
    
    for(int i =0;i<n; i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }

    cin >> amount;
    sort(coins.begin(),coins.end());
    reverse(coins.begin(),coins.end());
    // int ans = min_number_of_coins(amount);
    // ans == M ? cout<<"-1\n" : cout<< ans <<'\n';
    dp[0] = 0;
    for(int i = 1; i <= amount; i++){
        int ans = M;
        for(int j = 0; j < n; j++){
            if(i<coins[j])break;
            ans = min(ans,1+dp[i-coins[j]]);
        }
        dp[i] = ans;
    }

    cout << dp[amount];

    return 0;}