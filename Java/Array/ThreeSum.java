
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = {-1,0,1,2,-1,-4};
		System.out.println(threeSum(nums));
	}
	
	public static List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		Arrays.sort(nums);
		int target = 0;
		for(int i = 0; i < nums.length; i++) {
			int newTarget = target - nums[i];
			int left = i+1, right = nums.length - 1;
			while(left < right) {
				int twoSum = nums[left] + nums[right];
				if(twoSum < newTarget) {
					left++;
				} else if(twoSum > newTarget) {
					right--;
				} else {
					List<Integer> triplet = new ArrayList<Integer>();
					triplet.add(nums[i]);
					triplet.add(nums[left]);
					triplet.add(nums[right]);
					result.add(triplet);
					
					 while (left < right && nums[left] == triplet.get(1)) ++left;
                     while (left < right && nums[right] == triplet.get(2)) --right;
				}
			}
			while (i < nums.length - 1 && nums[i+1] == nums[i]) ++i;
		}
		return result;
        
    }

}
