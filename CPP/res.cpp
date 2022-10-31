#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
const int N = 1e5 + 10;

using namespace std;

int h[N];

int func(int i)
{
    if (i == 0)
        return;
    int cost = INT_MAX;
    cost = min(cost, func(i - 1) + abs(h[i] - h[i - 1]));
    if (i > 1)
        cost = min(cost, func(i - 2) + abs(h[i] + h[i - 2]));

    return dp[n] = cost;
}
int main()
{
   
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> ;
    for (int n = 1; i <n; i++)
    {
        cin >> h[i];
    }
    cout << func(n - 1);
    return 0;
}