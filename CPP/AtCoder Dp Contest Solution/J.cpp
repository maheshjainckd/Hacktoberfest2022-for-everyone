/*
J - Sushi  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 100 points

Problem Statement
There are N dishes, numbered 1,2,…,N. Initially, for each i (1≤i≤N), Dish i has ai(1≤ai≤3) pieces of sushi on it.

Taro will perform the following operation repeatedly until all the pieces of sushi are eaten:

Roll a die that shows the numbers 1,2,…,N with equal probabilities, and let i be the outcome. If there are some pieces of sushi on Dish i, eat one of them; if there is none, do nothing.
Find the expected number of times the operation is performed before all the pieces of sushi are eaten.

Constraints
All values in input are integers.
1≤N≤300
1≤ai≤3
Input
Input is given from Standard Input in the following format:

N
a1 a2 … aN
​
Output
Print the expected number of times the operation is performed before all the pieces of sushi are eaten. The output is considered correct when the relative difference is not greater than 10^−9
 .

Sample Input 1 
Copy
3
1 1 1
Sample Output 1 
Copy
5.5
The expected number of operations before the first piece of sushi is eaten, is 1. After that, the expected number of operations before the second sushi is eaten, is 1.5. After that, the expected number of operations before the third sushi is eaten, is 3. Thus, the expected total number of operations is 1+1.5+3=5.5.

Sample Input 2 
Copy
1
3
Sample Output 2 
Copy
3
Outputs such as 3.00, 3.000000003 and 2.999999997 will also be accepted.

Sample Input 3 
Copy
2
1 2
Sample Output 3 
Copy
4.5
Sample Input 4 
Copy
10
1 3 2 3 3 2 3 2 1 3
Sample Output 4 
Copy
54.48064457488221
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;
float n;

int arr[100];
float dp[100][100][100];

float solve(int one, int two, int three){
    if((one + two + three) == 0)return 0;

    if(dp[one][two][three]!=0)return dp[one][two][three];

    float total = (float)one + two + (float)three;
    return dp[one][two][three] = n/total + (one ? one*(solve(one-1,two,three))/total : 0) + (two ? two*(solve(one+1,two-1,three))/total : 0) + (three ? three*(solve(one,two+1,three-1))/total : 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

// total / number of non - zeros
    cin >> n;
    mii count;
    count.insert({1,0});
    count.insert({2,0});
    count.insert({3,0});

    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        count[arr[i]]++;
    }

    float ans = solve(count[1],count[2],count[3]);
    cout<<ans;

    return 0;}