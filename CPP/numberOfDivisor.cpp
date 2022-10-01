#include "bits/stdc++.h"
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

vector<ll> divisors(1e6 + 5 , 0);

void findNumDivisors() {
    for(ll i=2 ; i<=1e6+3 ; i++) {
        for(ll j=2*i ; j<=1e6+3 ; j+=i) {
            divisors[j]++;
        }
    }
}

void solve() {
    
    findNumDivisors();
}   

signed main() {

    int t = 1;
    // cin>>t;

    // cout<<fixed<<setprecision(10);
    for(int tc=1 ; tc<=t ; tc++) {
        // cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
