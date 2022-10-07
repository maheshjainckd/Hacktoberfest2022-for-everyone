#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
  return (n == 0) ? 1 : n * factorial(n - 1);
}

void lexicographicRank(string s)
{
  int len = s.length();
  int fac = factorial(len);
  int rank;
  
  int count[256] = {0};
  
  for(auto i : s)
    count[i]++;
  
  for(int i = 1; i < 256; i++)
    count[i] = count[i] + count[i - 1];
  
  for(int i = 0; i < len; i++)
  {
    fac = fac/ (len - 1);
    rank += (count[s[i] - i * fac);
    for(int j = s[i]; j < 256; j++)
      count[j]--;
  }
  cout << "Rank: " << rank;
                   
}        
  
int main()
{
  string s;
  cin >> s;
  lexicographicRank(s);
}
