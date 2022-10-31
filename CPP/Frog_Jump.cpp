#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
class Solution {
public:
   unordered_map < lli, int > visited;
   bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
      lli key = pos | k << 11;
      if(visited.find(key) != visited.end())return visited[key];
      for(int i = pos + 1; i < stones.size(); i++){
         int gap = stones[i] - stones[pos];
         if(gap < k - 1)continue;
         if(gap > k + 1){
            return visited[key] = false;
         }
         if(canCross(stones, i, gap))return visited[key] = true;
      }
      return visited[key] = (pos == stones.size() - 1);
   }
};
main(){
   Solution ob;
   vector<int> v = {0,1,3,5,6,8,12,17};
   cout << (ob.canCross(v));
}