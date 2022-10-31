// Print all unique permutations avoid duplicate
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void helper(vector<int> a,vector<vector<int> > &ans,int idx){
    if(idx==a.size()){
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++){
        if(i!=idx and a[idx]){
            continue;
        }
        swap(a[i],a[idx]);
        helper(a,ans,idx+1);
    }
}
vector<vector<int> > permute(vector<int> nums){
    sort(nums.begin(),nums.end());
    vector<vector<int> >ans;
    helper(nums,ans,0);
    return ans;
}
int32_t main()
{
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i: a)
        cin>>i;
    vector<vector<int> > res=permute(a);
    for(auto v: res ){
        for(auto i: v)
            coout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}