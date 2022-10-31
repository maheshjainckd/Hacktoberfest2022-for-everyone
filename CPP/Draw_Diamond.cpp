//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void printe(int num)
{
    if (num > 0)
    {
        for (int i = 1; i <= num; i++)
        {
            cout << "e";
        }
    }
}

void printo(int num)
{
    if (num > 0)
    {
        for (int i = 1; i <= num; i++)
        {
            cout << "o";
        }
    }
}

void printthediamond(int r, int c, int size)
{
    int i, j, k;
    for (k = 1; k <= r; k++)
    {
        for (i = 1; i <= size; i++)
        {
            for (j = 1; j <= c; j++)
            {
                printe(size - i);
                cout << "/";
                printo(2 * (i - 1));
                cout << "\\";
                printe(size - i);
            }
            cout << "\n";
        }

        for (i = 1; i <= size; i++)
        {
            for (j = 1; j <= c; j++)
            {
                printe(i - 1);
                cout << "\\";
                printo(2 * (size - i));
                cout << "/";
                printe(i - 1);
            }
            cout << "\n";
        }
    }
}

void solve(int t)
{
    int z = t;
    while (t--)
    {
        int r, c, s;
        // cin>>r>>c>>s;
        // printthediamond(r,c,s);
        printthediamond(2, 3, 2);
    }
}

int main()
{
    int t;
    // cin>>t;
    // solve(t);
    solve(1);
    return 0;
}
