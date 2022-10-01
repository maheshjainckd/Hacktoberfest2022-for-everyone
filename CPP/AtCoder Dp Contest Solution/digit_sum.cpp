/*
S - Digit Sum 
Problem Statement
Find the number of integers between 1 and K (inclusive) satisfying the following condition, modulo 10^9+7:

The sum of the digits in base ten is a multiple of D.
Constraints
All values in input are integers.
1≤K<10^10000
1≤D≤100
Input
Input is given from Standard Input in the following format:
K
D
Output
Print the number of integers satisfying the condition, modulo 10^9+7.

Sample Input 1 
Copy
30
4
Sample Output 1 
Copy
6
Those six integers are: 4,8,13,17,22 and 26.

Sample Input 2 
Copy
1000000009
1
Sample Output 2 
Copy
2
Be sure to print the number modulo 10^9+7.

Sample Input 3 
Copy
98765432109876543210
58
Sample Output 3 
Copy
635270834
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

string K;
int D;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> D;

    return 0;}