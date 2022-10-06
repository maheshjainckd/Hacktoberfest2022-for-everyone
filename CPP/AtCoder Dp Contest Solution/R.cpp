/*
R - Walk 

There is a simple directed graph G with N vertices, numbered 1,2,…,N.

For each i and j (1≤i,j≤N), you are given an integer aij that represents whether there is a directed edge from Vertex i to j. If aij=1, there is a directed edge from Vertex i to j; if aij=0, there is not.

Find the number of different directed paths of length K in G, modulo 10^9+7. We will also count a path that traverses the same edge multiple times.

Constraints
All values in input are integers.
1≤N≤50
1≤K≤10^18
aij is 0 or 1.
aii=0
Input
Input is given from Standard Input in the following format:

N K
a11 … a1N​
 :
aN1 … aNN
​ 
Output
Print the number of different directed paths of length K in G, modulo 10^9+7.

Sample Input 1 
Copy
4 2
0 1 0 0
0 0 1 1
0 0 0 1
1 0 0 0
Sample Output 1 
Copy
6
G is drawn in the figure below:



There are six directed paths of length 2:

1 → 2 → 3
1 → 2 → 4
2 → 3 → 4
2 → 4 → 1
3 → 4 → 1
4 → 1 → 2
Sample Input 2 
Copy
3 3
0 1 0
1 0 1
0 0 0
Sample Output 2 
Copy
3
G is drawn in the figure below:



There are three directed paths of length 3:

1 → 2 → 1 → 2
2 → 1 → 2 → 1
2 → 1 → 2 → 3
Sample Input 3 
Copy
6 2
0 0 0 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 0 1
0 0 0 0 0 0
Sample Output 3 
Copy
1
G is drawn in the figure below:



There is one directed path of length 2:

4 → 5 → 6
Sample Input 4 
Copy
1 1
0
Sample Output 4 
Copy
0
Sample Input 5 
Copy
10 1000000000000000000
0 0 1 1 0 0 0 1 1 0
0 0 0 0 0 1 1 1 0 0
0 1 0 0 0 1 0 1 0 1
1 1 1 0 1 1 0 1 1 0
0 1 1 1 0 1 0 1 1 1
0 0 0 1 0 0 1 0 1 0
0 0 0 1 1 0 0 1 0 1
1 0 0 0 1 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
1 0 1 1 1 0 1 1 1 0
Sample Output 5 
Copy
957538352
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

int N;
deq graph[100];
ll dp[51][1000];
ll cycles[51];

int solve(int index, int n){
    
    if(n == 0)return 1;
    if(n > 0 && graph[index].size()==0)return 0;

    if(dp[index][n]!=-1)return dp[index][n];

    int ways = 0;

    for(auto i : graph[index]){
        ways += solve(i,n-1);
    }
    return dp[index][n] = ways; 
}

// when K >>>> N this code won't work, Instead Count total number of cycles in the graph. Since, Itna barra path bs graph ke ek end se doosre tak jaane mein nahi aayega. Blaki ek hi path pr baar baar ghoomne se aayega

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    int K;
    cin >> N >> K;

    int x;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> x;
            if(x==1){graph[i].push_back(j);}
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans += solve(i,K);
    }

    cout << ans;

    return 0;}