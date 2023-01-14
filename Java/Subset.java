class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> list = new ArrayList();
        List<List<Integer>> ans = new ArrayList();
        subsequence(0, list, nums, ans);
        
        return ans;
    }
    
    public void subsequence(int index, List<Integer> list, int[] nums, List<List<Integer>> ans){
        if(index == nums.length){
            ans.add(new ArrayList(list));
            return;
        }
        list.add(nums[index]);
        subsequence(index+1, list, nums, ans);
        list.remove(list.size() - 1);
        subsequence(index+1, list, nums, ans);
    }
}
