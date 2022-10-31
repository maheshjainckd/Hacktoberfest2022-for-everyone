//Smallest Subsequence with k
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
signed main()
{
    int n, k;
    cout << "Enter value of N" << endl;
    cin >> n;
    cout << "Enter Value of K" << endl;
    cin >> k;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    priority_queue<int, vi> pq;
    rep(i, 0, n)
    {
        pq.push(a[i]);
    }
    int sum = 0;
    int cnt = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
        cnt++;
        if (sum >= k)
        {
            break;
        }
    }
    if (sum < k)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << cnt << endl;
    }

    return 0;
}
