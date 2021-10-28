
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class FourSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nums[] = {1,0,-1,0,-2,2};
		System.out.println(fourSum(nums,0));
	}
	
	public static List<List<Integer>> fourSum(int[] nums, int target) {
		ArrayList<List<Integer>> result = new ArrayList<List<Integer>>();
		Arrays.sort(nums);
		for(int i = 0; i < nums.length; i++) {
			for(int j = i+1; j < nums.length; j++) {
				int newTarget = target - (nums[i] + nums[j]);
				int left = j+1, right = nums.length - 1;
				while(left < right) {
					int twoSum = nums[left] + nums[right];
					if(twoSum < newTarget) {
						left++;
					} else if(twoSum > newTarget) {
						right--;
					} else {
						List<Integer> quad = new ArrayList<Integer>();
						quad.add(nums[i]);
						quad.add(nums[j]);
						quad.add(nums[left]);
						quad.add(nums[right]);
						result.add(quad);
						

                        // Processing the duplicates of left pointer
                        while (left < right && nums[left] == quad.get(2)) ++left;
                    
                        // Processing the duplicates of right pointer
                        while (left < right && nums[right] == quad.get(3)) --right;
					}
				}
				while(j + 1 < nums.length && nums[j + 1] == nums[j]) ++j;
			}
            while (i + 1 < nums.length && nums[i + 1] == nums[i]) ++i;
		}
		return result;
    }

}
