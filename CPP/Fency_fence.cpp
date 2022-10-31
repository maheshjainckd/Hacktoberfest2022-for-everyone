#include <bits/stdc++.h>
#define ll long long int
#define lp for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unordered_set<int> v;
        for (int i = 3; i < 100000; i++)
        {
            int a = (i - 2) * 180;
            if (a / i <= 180 && a % i == 0)
                v.insert(a / i);
        }
        // for (auto i : v)
        //     cout << i << " ";
        // cout << endl;
        int angle;
        cin >> angle;
        if (v.find(angle) != v.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}