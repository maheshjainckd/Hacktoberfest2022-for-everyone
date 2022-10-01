/*
O - Matching  
There are N men and N women, both numbered 1,2,…,N.

For each i,j (1≤i,j≤N), the compatibility of Man i and Woman j is given as an integer aij. If aij =1, Man i and Woman j are compatible; if aij=0, they are not.

Taro is trying to make N pairs, each consisting of a man and a woman who are compatible. Here, each man and each woman must belong to exactly one pair.

Find the number of ways in which Taro can make N pairs, modulo 10^9+7.

Constraints
All values in input are integers.
1≤N≤21
aij is 0 or 1.
Input
Input is given from Standard Input in the following format:

N
a11 … a1N 
:
aN1 … aNN
​
 
Output
Print the number of ways in which Taro can make N pairs, modulo 10^9+7.

Sample Input 1 
Copy
3
0 1 1
1 0 1
1 1 1
Sample Output 1 
Copy
3
There are three ways to make pairs, as follows ((i,j) denotes a pair of Man i and Woman j):

(1,2),(2,1),(3,3)
(1,2),(2,3),(3,1)
(1,3),(2,1),(3,2)
Sample Input 2 
Copy
4
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
Sample Output 2 
Copy
1
There is one way to make pairs, as follows:

(1,2),(2,4),(3,1),(4,3)
Sample Input 3 
Copy
1
0
Sample Output 3 
Copy
0
Sample Input 4 
Copy
21
0 0 0 0 0 0 0 1 1 0 1 1 1 1 0 0 0 1 0 0 1
1 1 1 0 0 1 0 0 0 1 0 0 0 0 1 1 1 0 1 1 0
0 0 1 1 1 1 0 1 1 0 0 1 0 0 1 1 0 0 0 1 1
0 1 1 0 1 1 0 1 0 1 0 0 1 0 0 0 0 0 1 1 0
1 1 0 0 1 0 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 1 1 0 1 1 1 0 1 1 1 0 0 0 1 1 1 1 0 0 1
0 1 0 0 0 1 0 1 0 0 0 1 1 1 0 0 1 1 0 1 0
0 0 0 0 1 1 0 0 1 1 0 0 0 0 0 1 1 1 1 1 1
0 0 1 0 0 1 0 0 1 0 1 1 0 0 1 0 1 0 1 1 1
0 0 0 0 1 1 0 0 1 1 1 0 0 0 0 1 1 0 0 0 1
0 1 1 0 1 1 0 0 1 1 0 0 0 1 1 1 1 0 1 1 0
0 0 1 0 0 1 1 1 1 0 1 1 0 1 1 1 0 0 0 0 1
0 1 1 0 0 1 1 1 1 0 0 0 1 0 1 1 0 1 0 1 1
1 1 1 1 1 0 0 0 0 1 0 0 1 1 0 1 1 1 0 0 1
0 0 0 1 1 0 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1
1 0 1 1 0 1 0 1 0 0 1 0 0 1 1 0 1 0 1 1 0
0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 1 1 0 0 1
0 0 0 1 0 0 1 1 0 1 0 1 0 1 1 0 0 1 1 0 1
0 0 0 0 1 1 1 0 1 0 1 1 1 0 1 1 0 0 1 1 0
1 1 0 1 1 0 0 1 1 0 1 1 0 1 1 1 1 1 0 1 0
1 0 0 1 1 0 1 1 1 1 1 0 1 0 1 1 0 0 0 0 0
Sample Output 4 
Copy
102515160
Be sure to print the number modulo 10^9 +7.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

ll dp[22][1<<22];
deq females[22];
int N;

ll solve(int male, ll bitmask){
    
    if(male<=0){
        bool x = true;
        for(int i = 1; i<=N;i++){
            if((bitmask & (1<<i))==0){
                x = false;
                break;
            }
        }
        return x ? 1 : 0;
    }

    if(dp[male][bitmask]!=-1)return (dp[male][bitmask]%M);

    ll ways = 0;
    
    for(auto i : females[male]){
        if((bitmask & (1<<i)) == 0){
            bitmask |= (1<<i);
            ways = ((ways%M) + (solve(male-1, bitmask)%M))%M;
            bitmask &= (~(1<<i));
        }
    }

    return dp[male][bitmask] = (ways%M);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> N;
    int x;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cin >> x;
            if(x==1){females[i].push_back(j);}
        }
    }

    int ans = solve(N,1)%M;
    cout<<ans;

    return 0;}