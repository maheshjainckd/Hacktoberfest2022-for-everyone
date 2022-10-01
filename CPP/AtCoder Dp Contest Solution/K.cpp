/*
K - Stones  / 
There is a set A={a1 ,a2 ,…,aN} consisting of N positive integers. Taro and Jiro will play the following game against each other.

Initially, we have a pile consisting of K stones. The two players perform the following operation alternately, starting from Taro:

Choose an element x in A, and remove exactly x stones from the pile.
A player loses when he becomes unable to play. Assuming that both players play optimally, determine the winner.

Constraints
All values in input are integers.
1≤N≤100
1≤K≤10^5
 
1≤a1<a2<⋯<aN
​
 ≤K
Input
Input is given from Standard Input in the following format:

N K
a1 a2 … aN
​
 
Output
If Taro will win, print First; if Jiro will win, print Second.

Sample Input 1 
Copy
2 4
2 3
Sample Output 1 
Copy
First
If Taro removes three stones, Jiro cannot make a move. Thus, Taro wins.

Sample Input 2 
Copy
2 5
2 3
Sample Output 2 
Copy
Second
Whatever Taro does in his operation, Jiro wins, as follows:

If Taro removes two stones, Jiro can remove three stones to make Taro unable to make a move.
If Taro removes three stones, Jiro can remove two stones to make Taro unable to make a move.
Sample Input 3 
Copy
2 7
2 3
Sample Output 3 
Copy
First
Taro should remove two stones. Then, whatever Jiro does in his operation, Taro wins, as follows:

If Jiro removes two stones, Taro can remove three stones to make Jiro unable to make a move.
If Jiro removes three stones, Taro can remove two stones to make Jiro unable to make a move.
Sample Input 4 
Copy
3 20
1 2 3
Sample Output 4 
Copy
Second
Sample Input 5 
Copy
3 21
1 2 3
Sample Output 5 
Copy
First
Sample Input 6 
Copy
1 100000
1
Sample Output 6 
Copy
Second
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int n;
deq stones;
int dp[2][100];

// 0 => Taro
// 1 => Jiro

int solve(int turn, int k){
    auto give = [](int turn){return (turn == 1) ? 0 : 1;};
    if(k<stones[0])return give(turn);

    if(dp[turn][k]!=-1)return dp[turn][k];

    int next = give(turn);;
    int ans = give(turn);;

    for(int i = 0; i<n; i++){
        if(k>=stones[i]){
        int z = solve(next,k-stones[i]);
        ans = [turn](int ans,int z){return (turn == 1) ? (ans | z) : (ans & z);}(ans,z);}
    }
    return dp[turn][k] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        stones.push_back(x);
    }

    int ans = solve(0,k);
    
    (ans == 0) ? cout<<"First" : cout<<"Second";

    return 0;}