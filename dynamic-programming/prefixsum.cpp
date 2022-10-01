#include<bits/stdc++.h>
const N = 100; // size of vector
using namespace std;

int main() 
{
  vector<int> qs(N+1, 0);
  for(int i=1;i<=N;++i){
    cin >> qs[i];
    qs[i] += qs[i-1];
  }
  
  // then when you need a sum of a range
  // e.g. sum of vector index 31 to 50
  // you can just print qs[end] - qs[begin-1]
	
  cout << qs[50] - qs[30];


}
