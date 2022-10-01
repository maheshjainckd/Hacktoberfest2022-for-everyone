/*
Problem
The Fibonacci sequence is defined as F(n) = F(n-1) + F(n-2). You have developed two sequences of numbers. The first sequence that uses the XOR operation instead of the addition method is called the Xoronacci number X(n). 
The second sequence that uses the XNOR operation instead of the addition method is called the XNoronacci number E(n). 



The first and second numbers of the sequence are as follows:
X(1) = E(1) = a
X(2) = E(2) = b

You have also defined the following constraint:

The minimum number of bits that that is used while representing the ith term must be greater than equal to 3. It must be equal to the minimum number of bits that is required while respresenting the maximum pair (first number, second number) of the respective sequences.

Notes:



Your task is to determine the value of max(X(n),E(n)).

Input format

First line: T denoting the number of test cases
Next T lines: Three integers a, b, and n
Output format

Print a single integer for each test case.

Constraints
T <= 10^5
a,b,n <= 10^12

Sample Input
3
3 4 2
4 5 3
325 265 1231
Sample Output
4
6
265
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

int X[100001];
int E[100001];

int XOR(int n){
    if(X[n]!=-1){return X[n];}
    else {return X[n] = (XOR(n-1) ^ XOR(n-2));}
}

int XNOR(int n){
    if(E[n]!=-1){return E[n];}
    else{
        return E[n] = (~(XNOR(n-1) ^ XNOR(n-2)));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        memset(X, -1, sizeof(X));
        memset(E, -1, sizeof(E));

        int a,b,n;
        cin>>a>>b>>n;
        X[1] = E[1] = a;
        X[2] = E[2] = b;

        int ans = max(XNOR(n),XOR(n));
        cout<<ans<<"\n";
    }


    return 0;}