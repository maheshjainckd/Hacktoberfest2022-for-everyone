/*
Partition Equal Subset Sum

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 
Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int dp[1000][1000];

int N;
int arr[100];

int func(int sum, int index){
    if(sum == 0) return 1;
    if(index >= N || sum < 0 )return 0;

    if(dp[sum][index]!=-1)return dp[sum][index];

    return dp[sum][index] = (func(sum - arr[index],index + 1) | func(sum,index + 1)); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin>>N;
    int sum = 0;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    int ans = (sum & 1) ? 0 : 1;

    if(ans){
        int x = (sum/2);
        ans = func(x,0);
    }

    cout << ans;

    return 0;}