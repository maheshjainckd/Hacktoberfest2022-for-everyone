/*
Vacation 
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the i-th day:

A: Swim in the sea. Gain ai  points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
1≤N≤10^5
1≤ai,bi,ci≤10^4
 
Input
Input is given from Standard Input in the following format:

N
a1 b1 c1
a2 b2 c2
​:
aN bN cN

Output
Print the maximum possible total points of happiness that Taro gains.
Sample Input 1 
3
10 40 70
20 50 80
30 60 90

Sample Output 1 
210
If Taro does activities in the order C, B, C, he will gain 70+50+90=210 points of happiness.

Sample Input 2 
1
100 10 1
Sample Output 2 
100

Sample Input 3 
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
Sample Output 3 
46
Taro should do activities in the order C, A, B, A, C, B, A.
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
int dp[100][4];
int a[3][100];

int solve(int day,int index){
    if(day>n){return 0;}

    if(dp[day][index]!=-1){return dp[day][index];}

    int ans = a[index][day];
    ans += (max(solve(day+1,(index+1)%3),solve(day+1,(index+2)%3)));       
    return dp[day][index] = ans; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[0][i]>>a[1][i]>>a[2][i];
    }

    int ans = max(solve(1,0),solve(1,1));
    ans = max(ans,solve(1,2));

    cout<<ans;

    return 0;}