//Short cut method useing STL 
//Permutations number of arrangements in array
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
void permute(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permute(a,idx + 1);
        swap(a[i], a[idx]);
    }
    return;
}

 
int main()
{
    int n;cout<<"Enter the number\n";
    cin>>n;
    for(auto &i:a)
     cin>>i;
    sort(a.begin(),a.end());
    do{
        ans.push_back(a);

    } while (next_permutation(a.begin(),a.end()));
    permute(a, 0);
    for (auto v : ans){
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
     
    
}