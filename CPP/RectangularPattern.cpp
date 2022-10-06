#include <bits/stdc++.h>
using namespace std;

void printRectPattern(int c1, int c2, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (max(abs(c1 - i), abs(c2 - j))) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int c1 = 2;
    int c2 = 2;
    int n = 5;

    printRectPattern(c1, c2, n);
    return 0;
}

// 2 2 2 2 2
// 2 1 1 1 2
// 2 1 0 1 2
// 2 1 1 1 2
// 2 2 2 2 2