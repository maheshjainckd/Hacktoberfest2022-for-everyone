class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maximum=INT_MIN;
        for(auto i:nums){
            sum+=i;
            maximum=max(sum,maximum);
            if(sum<0)
                sum=0;
        }
        return maximum;
    }
};