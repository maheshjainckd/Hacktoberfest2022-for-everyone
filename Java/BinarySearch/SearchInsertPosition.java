
public class SearchInsertPosition {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = {1,3,5,6};
		System.out.println(searchInsert(nums, 7));
	}
	
	public static int searchInsert(int[] nums, int target) {
		int position = binarySearch(nums, 0, nums.length-1, target);
		if(position == -1) {
			for(int i = 0; i < nums.length-1; i++) {
				if((target > nums[i]) && (target < nums[i+1])) {
					position = i+1;
					break;
				}
			}
			if(target > nums[nums.length - 1]) {
				position = nums.length;
			}
			if(target < nums[0]) {
				position = 0;
			}
		}
		return position;
        
    }
	
	static int binarySearch(int[] nums, int low, int high, int target) {
		if(high >= low) {
			if(nums[low] == target) return low;
			if(nums[high] == target) return high;
			int mid = low + (high-low)/2;
			if(nums[mid] == target) return mid;
			if(nums[mid] < target) {
				return binarySearch(nums, mid+1, high, target);
			} else if(nums[mid] > target) {
				return binarySearch(nums, low, mid-1, target);
			}
		}
		return -1;
	}

}
