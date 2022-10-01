/*
Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int nums[1000];
int dp[1000];
int total;

int func(int n){
    if(n == (total - 1))return 1;
    if(dp[n]!=-1)return dp[n];
    int ans = 1;

    for(int i = n + 1; i < total; i++){
        if(nums[i]>nums[n]){ans = max(ans,1+func(i));}
    }
    return dp[n] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> total;

    for(int i = 0;i<total;i++){
        cin >> nums[i];
    }

    int ans = 1;

    for(int i = 0;i<total;i++){
        ans = max(ans,func(i));
    }

    cout << ans;

    return 0;}