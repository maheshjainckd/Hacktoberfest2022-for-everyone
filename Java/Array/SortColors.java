

public class SortColors {

	public static void main(String[] args) {
		int nums[] = {2,0,1};
		sortColors(nums);
		for(int i: nums)
			System.out.println(i);

	}
	public static void sortColors(int[] nums) {
        int high = nums.length-1;
        int mid = 0;
        int low = 0;
        while(mid <= high) {
            switch(nums[mid]) {
	            case 0: {
	                int temp = nums[mid];
	                nums[mid] = nums[low];
	                nums[low] = temp;
	                mid++;
	                low++;
	                break;
	            }
	            case 1: {
	                mid++;
	                break;
	            }
	            case 2: {
	                int temp = nums[mid];
	                nums[mid] = nums[high];
	                nums[high] = temp;
	                high--;
	                break;
	            }
            }
            
        }
    }

}
