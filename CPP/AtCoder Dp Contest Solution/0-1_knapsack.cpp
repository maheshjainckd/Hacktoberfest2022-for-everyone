/*
0-1 => Ya item ko uthao ya mat uthao aadha ya dobara nhi utha sakte
Problem Statement
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi and a value of vi

Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^5
1≤wi≤W
1≤vi≤10^9
 
Input
Input is given from Standard Input in the following format:

N W
w1 v1
​w2 v2 
:
wN vN
​
 
Output
Print the maximum possible sum of the values of items that Taro takes home.

Sample Input 1 
Copy
3 8
3 30
4 50
5 60
Sample Output 1 
Copy
90
Items 1 and 3 should be taken. Then, the sum of the weights is 3+5=8, and the sum of the values is 30+60=90.

Sample Input 2 
Copy
5 5
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
Sample Output 2 
Copy
5000000000
The answer may not fit into a 32-bit integer type.

Sample Input 3 
Copy
6 15
6 5
5 6
6 4
6 6
3 5
7 2
Sample Output 3 
Copy
17
Items 2,4 and 5 should be taken. Then, the sum of the weights is 5+6+3=14, and the sum of the values is 6+6+5=17.
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
int N,W;
pair<int, int> p[1000];

int func(int weight, int index){
    if(index >= N)return 0;

    if(dp[weight][index]!=-1)return dp[weight][index];

    return dp[weight][index] = (weight >=p[index].first) ? max(func(weight,index+1),p[index].second+func(weight-p[index].first,index + 1)) : func(weight,index+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> N >> W;

    for(int i = 0; i < N; i++){
        int w,v;
        cin >> w >> v;
        p[i] = make_pair(w,v);
    }

    int ans = func(W,0);

    cout<<ans<<"\n";

    return 0;}