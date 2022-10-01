/*
H - Grid 1  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
There is a grid with H horizontal rows and W vertical columns. Let (i,j) denote the square at the i-th row from the top and the j-th column from the left.

For each i and j (1≤i≤H, 1≤j≤W), Square (i,j) is described by a character a 
i,j
​
 . If a 
i,j
​
  is ., Square (i,j) is an empty square; if a 
i,j
​
  is #, Square (i,j) is a wall square. It is guaranteed that Squares (1,1) and (H,W) are empty squares.

Taro will start from Square (1,1) and reach (H,W) by repeatedly moving right or down to an adjacent empty square.

Find the number of Taro's paths from Square (1,1) to (H,W). As the answer can be extremely large, find the count modulo 10 
9
 +7.

Constraints
H and W are integers.
2≤H,W≤1000
a 
i,j
​
  is . or #.
Squares (1,1) and (H,W) are empty squares.
Input
Input is given from Standard Input in the following format:

H W
a1,1 … a1,W 
:
aH,1 … aH,W
​
 
Output
Print the number of Taro's paths from Square (1,1) to (H,W), modulo 10^9+7.

Sample Input 1 
Copy
3 4
...#
.#..
....
Sample Output 1 
Copy
3
There are three paths as follows:



Sample Input 2 
Copy
5 2
..
#.
..
.#
..
Sample Output 2 
Copy
0
There may be no paths.

Sample Input 3 
Copy
5 5
..#..
.....
#...#
.....
..#..
Sample Output 3 
Copy
24
Sample Input 4 
Copy
20 20
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
Sample Output 4 
Copy
345263555
Be sure to print the count modulo 10^9+7.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

char grid[100][100];
int H,W;
ll dp[100][100];

int solve(int x,int y){
    if(x==H && y==W)return (1%M);
    if(x>H || y>W || x<=0 || y<=0)return 0;

    if(dp[x][y]!=-1)return dp[x][y];

    ll ans = 0;

    if(x<H && grid[x+1][y]=='.')ans = dp[x+1][y]!=-1 ? ((ans%M) + (dp[x+1][y]%M))%M : ((ans%M) + (solve(x+1,y)%M))%M;
    if(y<W && grid[x][y+1]=='.')ans = dp[x][y+1]!=-1 ? ((ans%M) +(dp[x][y+1]%M))%M : ((ans%M)+(solve(x,y+1)%M))%M;

    return dp[x][y] = (ans%M);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> H >> W;

    for(int i = 1; i<= H;i++){
        for(int j = 1; j<= W;j++){
            cin >> grid[i][j];
        }
    }

    cout<< solve(1,1);

    return 0;}