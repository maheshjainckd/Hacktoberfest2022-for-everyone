//Heap Sort
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
// define int long long
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

using namespace std;
int main()
{
    // priority_queue<int, vector<int>> pq;
    // pq.push(2);
    // pq.push(3);
    // pq.push(1);
    // cout << pq.top() << endl;
    // pq.pop();
    // cout << pq.top() << endl;
    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(2);
    pqm.push(1);
    pqm.push(3);
    cout << pqm.top() << endl;
    pqm.pop();
    cout << pqm.top() << endl;

    return 0;
}