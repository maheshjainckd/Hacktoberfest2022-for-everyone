//Heap Merge sort k sorted arrays
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>

using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
signed main()
{
    int k;
    cout << "Enter " << endl;
    cin >> k;
    vector<vector<int>> a(k);
    rep(i, 0, k)
    {
        int size;
        cout << "Enter the Size" << endl;
        cin >> size;

        a[i] = vector<int>(size);
        rep(j, 0, size)
        {
            cin >> a[i][j];
        }
    }
    vector<int> idx(k, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    rep(i, 0, k)
    {
        pq.push({a[i][0], i});
    }
    vi ans;
    while (!pq.empty())
    {
        pii x = pq.top();
        pq.pop();
        ans.push_back(x.ff);
        if (idx[x.ss] + 1 < a[x.ss].size())
        {
            pii p;
            p.ff = a[x.ss][idx[x.ss] + 1];
            p.ss = x.ss;
            pq.push(p);
                }
        idx[x.ss] += 1;
    }
    rep(i, 0, ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}