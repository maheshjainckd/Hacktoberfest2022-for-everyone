/*
P - Independent Set  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
There is a tree with N vertices, numbered 1,2,…,N. For each i (1≤i≤N−1), the i-th edge connects Vertex xi and yi.
Taro has decided to paint each vertex in white or black. Here, it is not allowed to paint two adjacent vertices both in black.

Find the number of ways in which the vertices can be painted, modulo 10^9+7. 

Constraints
All values in input are integers.
1≤N≤10^5
1≤xi,yi≤N
The given graph is a tree.
Input
Input is given from Standard Input in the following format:

N
x1 y1
​x2 y2 
:
xN−1 yN−1 
Output
Print the number of ways in which the vertices can be painted, modulo 10^9+7.

Sample Input 1 
Copy
3
1 2
2 3
Sample Output 1 
Copy
5
There are five ways to paint the vertices, as follows:



Sample Input 2 
Copy
4
1 2
1 3
1 4
Sample Output 2 
Copy
9
There are nine ways to paint the vertices, as follows:



Sample Input 3 
Copy
1
Sample Output 3 
Copy
2
Sample Input 4 
Copy
10
8 5
10 8
6 5
1 5
4 8
2 10
3 6
9 2
1 7
Sample Output 4 
Copy
157
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

int solve(int index, int arr[]){
    if(index <= 0){return 1;}

    bool x = true;
    for(auto i : graph[index]){
        if(arr[i] == 1){x = false;break;}
    }
    int ways = 0;
    ways += solve(index-1,arr);
    
    if(x){
        arr[index] = 1;
        ways += solve(index-1,arr);
        arr[index] = 0;
    }

    return ways;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int a,b;
    for(int i = 0; i < (N-1);i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int arr[N+1] = {0};

    int ans = solve(N,arr);

    cout<<ans;

    return 0;}