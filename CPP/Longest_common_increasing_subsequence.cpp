#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 1e18
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define small 0
#define MAXSIZE 100000
const int N = 200005;
#define endl "\n"
using namespace std;  
using namespace __gnu_pbds;
#define debug(x) cout << #x << " " << x << endl;
#define debug1(x) cout << #x << " " << x << " ";
#define debug2(x) cout<<"["<<#x<<" = "<<x<<"]\n";

ll index=0;
ll valod=0;
vector<ll> construct(vector<ll> v1,vector<ll> v2){
 ll n1=sz(v1);
 ll n2=sz(v2);
vector<ll> dp(n2+1),helper(n2+1);
 for(ll i=1;i<=n1;i++){
  ll current=0;
  for(ll j=1;j<=n2;j++){
    if(v1[i]==v2[j]){
      dp[j]=dp[current]+1;
      helper[j]=current;
    }
   else if(v2[j]<v1[i] && dp[j]>dp[current]){
        current=j;
    }
  }
 }
 ll val2=0;
 for(ll i=1;i<=n2;i++){
  if(dp[i] > dp[val2]){
    val2=i;
    index=i;
  }
 }
 valod=dp[val2];
 vector<ll> ans;
 while(val2){
  ans.push_back(v2[val2]);
  val2=helper[val2];
 }
 return ans;
}
vector<ll> lcs(vector<ll> v1,vector<ll> v2){
  vector<ll> helper;
  ll n1=sz(v1);
  ll n2=sz(v2);
  ll dp[n1][n2];
  for(ll i=0;i<n1;i++){
    for(ll j=0;j<n2;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
    }
  }
  for(ll i=1;i<n1;i++){
    for(ll j=1;j<n2;j++){
      if(v1[i-1]==v2[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
      }
      else{
        dp[i][j]=max((dp[i-1][j]),dp[i][j-1]);
      }
    }
  }

  ll p1=n1;
  ll p2=n2;
  while(p1 > 0 && p2 > 0){
    if(v1[p1-1]==v2[p2-1]){
      helper.push_back(v1[p1-1]);
      p1--;
      p2--;
    }
    else{
      if(dp[p1-1][p2] > dp[p1][p2-1]){
        p1--;
      }
      else{
        p2--;
      }
    }
  }
  reverse(all(helper));
  return helper;
}
vector<ll> lis(vector<ll> v){
  set<ll> s;
  for(auto i:v){
    s.insert(i);
  }
  vector<ll> helper;
  for(auto i:s){
    helper.push_back(i);
  }
  vector<ll> helper1=lcs(v,helper);
  return helper1;
}
vector<ll> common(vector<ll> v1,vector<ll> v2){
  vector<ll> helperl;
  set<ll> s1;
  for(auto i:v1){
    s1.insert(i);
  }
  for(auto i:v2){
    if(s1.count(i)){
      helperl.push_back(i);
    }
  }
  return helperl;
}
void solve(){
  ll n1;
  cin >> n1;
  vector<ll> v1(n1+1);
  for(ll i=0;i<n1;i++){
    cin >> v1[i+1];
  }
  ll n2;
  cin >> n2;
  vector<ll> v2(n2+1);
  for(ll i=0;i<n2;i++){
    cin >> v2[i+1];
  }
  vector<ll> ans3=construct(v1,v2);
  if(ans3.size() > 0){
    ll val1=*max_element(all(ans3));
  }
  vector<ll> ans1=common(v1,v2);
  vector<ll> ans2=common(v2,v1);
  vector<ll> ans4=lis(ans1);
  vector<ll> ans5=lis(ans2);
  cout << valod << endl;
  reverse(all(ans3));
  for(auto i:ans3){
    cout << i << " ";
  }
}

int main(){
init(); 
IOS;
ll t=1;
// cin >> t;
while(t--){
solve();
}
return 0;
}
// author pritish_panda
//kalinga institute of industrial technology
