/*
N - Slimes  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
There are N slimes lining up in a row. Initially, the i-th slime from the left has a size of ai.

Taro is trying to combine all the slimes into a larger slime. He will perform the following operation repeatedly until there is only one slime:

Choose two adjacent slimes, and combine them into a new slime. The new slime has a size of x+y, where x and y are the sizes of the slimes before combining them. Here, a cost of x+y is incurred. The positional relationship of the slimes does not change while combining slimes.
Find the minimum possible total cost incurred.

Constraints
All values in input are integers.
2≤N≤400
1≤ai≤10^9
 
Input
Input is given from Standard Input in the following format:

N
a1 a2 … aN​
 
Output
Print the minimum possible total cost incurred.

Sample Input 1 
Copy
4
10 20 30 40
Sample Output 1 
Copy
190
Taro should do as follows (slimes being combined are shown in bold):

(10, 20, 30, 40) → (30, 30, 40)
(30, 30, 40) → (60, 40)
(60, 40) → (100)
Sample Input 2 
Copy
5
10 10 10 10 10
Sample Output 2 
Copy
120
Taro should do, for example, as follows:

(10, 10, 10, 10, 10) → (20, 10, 10, 10)
(20, 10, 10, 10) → (20, 20, 10)
(20, 20, 10) → (20, 30)
(20, 30) → (50)
Sample Input 3 
Copy
3
1000000000 1000000000 1000000000
Sample Output 3 
Copy
5000000000
The answer may not fit into a 32-bit integer type.

Sample Input 4 
Copy
6
7 6 8 6 1 1
Sample Output 4 
Copy
68
Taro should do, for example, as follows:

(7, 6, 8, 6, 1, 1) → (7, 6, 8, 6, 2)
(7, 6, 8, 6, 2) → (7, 6, 8, 8)
(7, 6, 8, 8) → (13, 8, 8)
(13, 8, 8) → (13, 16)
(13, 16) → (29)
*/

// #include<bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define deq deque<int>
// #define mii map<int,int>
// #define pii pair<int,int>
// int M = 1000000007;
// using namespace std;

// int func(int n, deq seq){
//     if(n==1)return 0;

//     int ans = 0;
//     int mi = 0, ms = (seq[0]+seq[1]);
//     for(int i=0; i<(n-1); i++){
//         if((seq[i]+seq[i+1])<ms){
//             mi = i;
//             ms = seq[i] + seq[i+1]; 
//         }
//     }
//     seq[mi+1] = ms;
//     seq.erase(seq.begin() + mi);

//     return ms + func(n-1,seq);
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int n;
//     cin >> n;

//     int c;
//     deq seq;

//     for(int i = 0;i<n; i++){
//         cin >> c;
//         seq.push_back(c);
//     }    

//     int ans = func(n,seq);
//     cout<<ans;
//     return 0;}

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int prefix_sum[407];
int arr[407];
int dp[407][407];

ull solve(int start, int end){
    if(start == end)return 0;
    if(start > end)return M;

    if(dp[start][end] != -1)return dp[start][end];

    ull ans = ULLONG_MAX;
    for(int i = start; i < end; i++){
        ans = min(ans,solve(start,i) + solve(i+1,end)+ 0LL + prefix_sum[end]-prefix_sum[start-1]);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    cout << solve(1,n);

    return 0;}