/*
Subset Sum Problem!

Given an integer array A  of size N.

You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

If there exist a subset then return 1 else return 0.



Problem Constraints
1 <= N <= 100

1 <= A[i] <= 100

1 <= B <= 105



Input Format
First argument is an integer array A.

Second argument is an integer B.



Output Format
Return 1 if there exist a subset with sum B else return 0.



Example Input
Input 1:

 A = [3, 34, 4, 12, 5, 2]
 B = 9
Input 2:

 A = [3, 34, 4, 12, 5, 2]
 B = 30


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 There is a subset (4, 5) with sum 9.
Explanation 2:

 There is no subset that add up to 30.

*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int A[100];
int dp[1000][100];
int n;

int subset_sum(int B,int index){
    if(B==0)return 1;
    if(index>n || B<0)return 0;

    if(dp[B][index]!=-1)return dp[B][index];

    return dp[B][index] = (B >= A[index]) ? ( subset_sum(B-A[index],index+1) | subset_sum(B,index+1) ): subset_sum(B,index+1); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }

    int B;
    cin >> B;

    cout<<subset_sum(B,1);

    return 0;}