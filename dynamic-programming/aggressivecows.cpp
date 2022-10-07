//problem link-https://www.spoj.com/problems/AGGRCOW/
//time complexity-O(nlogn)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool check(ll mid,ll n,vector<ll>&stall,ll cows)
{
    ll cnt=1;
    ll prev=stall[0];
    for(int i=1;i<n;i++)
    {
        if(stall[i]-prev>=mid)
        {
            cnt++;
            prev=stall[i];
        }
    }
    if(cnt>=cows) return true;
    return false;

}
void solve()
{
    ll n,c;
    cin>>n>>c;
    lv(stall)(n);
    fr(ll,i,0,n) cin>>stall[i];

    sort(all(stall));

    ll low=0,high=stall[n-1]-stall[0];
    while(low<=high)
    {
        ll mid=low+(high-low)/2;
        if(check(mid,n,stall,c))
        {
            low=mid+1;

        }
        else high=mid-1;
    }
    cout<<high;
}
int main()
{
  fast;
  int t;
  t = 1;
  cin >> t;
  for(int i=1;i<=t;i++)
  {
    solve();
    cout << "\n";
  }
    
}
//sample input
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9
//sample output
//3