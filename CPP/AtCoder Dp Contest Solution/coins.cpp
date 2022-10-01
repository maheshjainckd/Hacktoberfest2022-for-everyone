/*
Coins
Let N be a positive odd number.
There are N coins, numbered 1,2,…,N. For each i (1≤i≤N), when Coin i is tossed, it comes up heads with probability pi and tails with probability 1−pi
Taro has tossed all the N coins. Find the probability of having more heads than tails.

Constraints
N is an odd number.
1≤N≤2999
pi is a real number and has two decimal places.
0<pi<1
Input
Input is given from Standard Input in the following format:

N
p1 p2 … pN
​
Output
Print the probability of having more heads than tails. The output is considered correct when the absolute error is not greater than 10^−9
 .

Sample Input 1 
Copy
3
0.30 0.60 0.80
Sample Output 1 
Copy
0.612
The probability of each case where we have more heads than tails is as follows:

The probability of having (Coin1,Coin2,Coin3)=(Head,Head,Head) is 0.3×0.6×0.8=0.144;
The probability of having (Coin1,Coin2,Coin3)=(Tail,Head,Head) is 0.7×0.6×0.8=0.336;
The probability of having (Coin1,Coin2,Coin3)=(Head,Tail,Head) is 0.3×0.4×0.8=0.096;
The probability of having (Coin1,Coin2,Coin3)=(Head,Head,Tail) is 0.3×0.6×0.2=0.036.
Thus, the probability of having more heads than tails is 0.144+0.336+0.096+0.036=0.612.

Sample Input 2 
Copy
1
0.50
Sample Output 2 
Copy
0.5
Outputs such as 0.500, 0.500000001 and 0.499999999 are also considered correct.

Sample Input 3 
Copy
5
0.42 0.01 0.42 0.99 0.42
Sample Output 3 
Copy
0.3821815872
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

// dp[heads required][index] => Is index se required number of heads aane ki kya probability h
deque<float> answers;
float dp[100][100];
int req;
float heads[100];

float solve(float all_heads, int n, int index){
    if(index<=0 && n>=req){return all_heads;}
    if(n<req || index<=0){return 0;}

    if(dp[n][index]!=0)return dp[n][index];

    if(n == req){
        for(int i = 1; i<=index;i++){
            all_heads*=heads[i];
        }
        return all_heads;}

    float ans = 0;
    float z = all_heads * heads[index];
    ans += solve(z, n, index-1);

    if((n-1)>=req){
        all_heads *= (1-heads[index]); 
        ans += solve(all_heads, n-1, index-1);
    }

    return dp[n][index] = ans;
    // return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;

    req = (n&1) ? (n/2 + 1) : (n/2);

    for(int i = 1; i <= n; i++){
        cin >> heads[i];
    }

    float ans = solve(1,n,n);
    cout <<ans<<"\n";

    for(auto i : answers){
        cout<<i<<" ";
    }

    return 0;}