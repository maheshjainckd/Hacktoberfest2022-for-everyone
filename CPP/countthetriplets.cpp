#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int c = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = j + 1;
            while (k < n)
            {

                if (v[i] + v[j] == v[k])
                {
                    j++;
                    c++;
                }
                else if(v[i]+v[j]<v[k])
                {
                    j++;
                    k--;
                }
                k++;
            }
        }
        if(c==0){
            cout<<-1<<endl;
        }
        else
            cout<<c<<endl;
    }
}
