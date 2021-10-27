class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
            
        unordered_map<int, int> map;
        
        for(int num : nums)
            map[num]++;
        
        for(auto s : map)
        {
            if(s.second == 1)
                return s.first;
        }
        return 0;
    }
};
