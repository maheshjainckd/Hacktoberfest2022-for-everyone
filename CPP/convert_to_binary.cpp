#include <bits/stdc++.h>
using namespace std;

int convert(int n){
    int ans=0,p=1;

    while(n>0){
      int last_bit = n&1;
      ans = ans + p*last_bit;
      p=p*10;
      n= n>>1;
    }

    return ans;
}

int main(){
    cout << convert(15);
}
