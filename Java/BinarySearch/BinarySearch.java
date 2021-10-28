
public class BinarySearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = {-1,0,3,5,9,12};
		System.out.println(search(nums,2));
	}
	
	public static int search(int[] nums, int target) {
		return binarySearch(nums, 0, nums.length-1, target);
        
    }
	
	static int binarySearch(int[] nums, int low, int high, int target) {
		if(high >= low) {
			if(nums[low] == target) return low;
			if(nums[high] == target) return high;
			int mid = low + (high-low)/2;
			if(nums[mid] == target) return mid;
			if(nums[mid] < target) {
				System.out.println("Mid" +high);
				return binarySearch(nums, mid+1, high, target);
			} else if(nums[mid] > target) {
				return binarySearch(nums, low, mid-1, target);
			}
		}
		return -1;
	}

}
