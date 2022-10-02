/*In a nums array of length n, there are total 2^n possible subsets.
The idea is that we use bitmasks of n bits to present the state of subsets, mask in [0, 1, ... 2^n-1]. If the ith bit in the mask is 1 means nums[i] exists
in the subset presented by mask.
Since the nums array may contain duplicate numbers, so in the 2^n subsets, it may contain duplicate subsets.
We need to sort nums array to ensure all the generated subsets will also be sorted. This helps to identify duplicates.
For example: subsets {3, 1, 3}, {1, 3, 3}, {3, 3, 1} will become {1, 3, 3}.
We need to hash the subset and add into a HashTable, let's name seen, to check for duplicates.
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > subsetsWithDup(vector<int> &nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  unordered_set<string> s;
  for (int mask = 0, size = 1 << n; mask < size; ++mask) {
    vector<int> subset;
    string st = "";
    for (int i = 0; i < n; i++) {
      int bit = (mask >> i) & 1; // Get i_th bit of mask
      if (bit == 1) {
        subset.push_back(nums[i]);
        st += to_string(nums[i]) + ",";
        }
   }
   if (!s.count(st)) {
     ans.push_back(subset);
     s.insert(st);
   }
  }
  return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> num(n);
  //input of array
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
  
  // calling of function for subset generation
	vector<vector<int> > allsubsets = subsetsWithDup(num);
  
	// print all subset 
	for (int i = 0; i < allsubsets.size(); i++) {
        for (int j = 0; j < allsubsets[i].size(); j++)
            cout << allsubsets[i][j] << " ";
        cout << endl;
    }
 
    return 0;
	
}

