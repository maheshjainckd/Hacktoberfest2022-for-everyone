/*
Q - Flowers  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
There are N flowers arranged in a row. For each i (1≤i≤N), the height and the beauty of the i-th flower from the left is hi and ai, respectively. Here, h1,h2,…,hN are all distinct.

Taro is pulling out some flowers so that the following condition is met:

The heights of the remaining flowers are monotonically increasing from left to right.
Find the maximum possible sum of the beauties of the remaining flowers.

Constraints
All values in input are integers.
1≤N≤2×10^5
1≤hi≤N
h1,h2,…,hN are all distinct.
1≤ai≤10^9
 
Input
Input is given from Standard Input in the following format:

N
h1 h2 … hN
a1 a2 … aN
 
Output
Print the maximum possible sum of the beauties of the remaining flowers.

Sample Input 1 
4
3 1 4 2
10 20 30 40
Sample Output 1 
60
We should keep the second and fourth flowers from the left. Then, the heights would be 1,2 from left to right, which is monotonically increasing, and the sum of the beauties would be 20+40=60.

Sample Input 2 
1
1
10
Sample Output 2 
10
The condition is met already at the beginning.

Sample Input 3 
5
1 2 3 4 5
1000000000 1000000000 1000000000 1000000000 1000000000
Sample Output 3 
5000000000
The answer may not fit into a 32-bit integer type.

Sample Input 4 
9
4 2 5 8 3 6 1 7 9
6 8 8 4 6 3 5 7 5
Sample Output 4 
31
We should keep the second, third, sixth, eighth and ninth flowers from the left.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int N,h[100],a[100];
int dp[100][100];

int solve(int index,int x){

    if(index == 0){
        return 0;
    }

    if(dp[index][x]!=-1)return dp[index][x];

    int ans = 0;

    if(h[index]>h[x]){
        ans = solve(index - 1, x);
    }
    else{
        ans = max(a[index] + solve(index-1,index) , solve(index-1,x));
    }

    return dp[index][x] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }

    int ans = solve(N,N);
    cout << ans;

    return 0;}

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int N,h[100],a[100];

int solve(int index){
    if(index == 0)return 0;

    int ans = 0;

    for(int i = 0; i<index; i++){
        if(h[i]<h[index]){ans = max(ans,a[index] + solve(i));}
    }
    return ans;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }

    int ans = INT_MIN;

    for(int i = 1; i <= N; i++){
        ans = max(ans,solve(i));
    }

    cout<<ans;

    return 0;}