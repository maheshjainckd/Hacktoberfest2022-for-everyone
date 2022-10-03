#include <bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin >> t;
      while (t--){
            int N;
            cin>>N;
            cout<<round(pow(0.143*N,N))<<" "<<endl;
      }
      return 0;
}