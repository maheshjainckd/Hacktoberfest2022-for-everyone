#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;   
    cin >> n; // Taking the input that represetns number of requests to the system.
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string str;    
        cin >> str;         // Taking input of the string
        m[str]++;
        if (m[str] == 1)
            cout << "OK" << endl;
        else
            cout << str << m[str] - 1 << endl;
    }
    return 0;
}