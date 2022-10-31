class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return 0
        end = 0 + nums[0]
        start = 0
        step = 1
        maxDis = 0 + nums[0]
        while end < len(nums) - 1:
            for i in range(start + 1, end + 1):
                # greedy
                maxDis = max(maxDis, nums[i] + i)
            start = end
            end = maxDis
            step += 1
        return step
