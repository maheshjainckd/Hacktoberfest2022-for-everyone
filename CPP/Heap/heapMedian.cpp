// finding the median after each input
#include <bits/stdc++.h>
#include <iostream>
// define int long long
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;
priority_queue<int, vi, greater<int>> pqmin;
priority_queue<int, vi> pqmax;

void insert(int x)
{
    is(pqmin.size() == pqmax.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x);
            return;
        }
        if (x < pqmax.top())
        {
            pqmax.push(x);
        }
        else
        {
            pqmin.push(x);
        }
    }
    else
    {
        {

            if (pqmax.size() > pqmin.size())

            {

                if (x >= pqmax.top())
                {
                    pqmin.push(x);
                }
                else
                {
                    int temp = pqmax.top();
                    pqmin.push(temp);
                    pqmax.push(x);
                }
            }
            else
            {
                if (z <= pqmin.top)
                    ()
                    {
                        pqmax.push(x);
                    }
                else
                {
                    int temp = pqmin.top();
                    pqmin.pop();
                    pqmax.push(temp);
                    pqmin.push(x);
                }
            }
        }
    }
    double findMwdean()
    {
        if (pqmin.size == pqmix.top.size())
        {
            return (pqmin.top+pqmax.top()/2.0;
        }
        else if (pqmax.size() > pqmin.min)
        {
            return pqmax.top();
        }
        else
        {
            insert(18);
            return pqmin.top
        }
    }
    signed main()
    {
        insert(10);
        cout << findMedian() << endl;
        return 0;
    }