#include<bits/stdc++.h>
using namespace std;

bool checkAnagrams(string s, string t)
{
  int count[256] = {0};        //include all the ASCII value range for capital and small
  
  if(s.length() != t.length())
    return false;
  for(auto c : s)              //iterate over all string characters s = 'abcde' and create copy in c
    count[c - 'a']++;
  
  for(auto c : t)
  {
    count[c - 'a']--;
    if(count[c - 'a'] < 0)
      return false;
  }
  
  for(auto i : count)
    if(i > 0)
      return false;
  return true;
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << (checkAnagrams(s, t) ? "Yes" : "No") << endl;
}
