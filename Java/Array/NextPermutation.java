
public class NextPermutation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {3,2,1};
		nextPermutation(arr);
	}
	public static void nextPermutation(int[] nums) {
		// Step 0
		if(nums == null || nums.length <= 1) return;
		// Step 1
		boolean flag = false;
		int lowValueIndex = -1;
		int greaterThanLowValueIndex = nums[nums.length - 1];
		for(int i = nums.length - 1; i > 0; i--) {
			if(nums[i] > nums[i-1]) {
				lowValueIndex = i-1;
				flag = true;
				break;
			}
		}
		// Step 2
		if(flag) {
			for(int i = nums.length - 1; i >= 0; i--) {
				if(nums[lowValueIndex] < nums[i]) {
					greaterThanLowValueIndex = i;
					break;
				}
			}
		}
		// Step 3
		if(flag) {
			swap(nums, lowValueIndex, greaterThanLowValueIndex);
		}
		// Step 4 : Reverse
		reverse(nums, lowValueIndex+1, nums.length - 1);
	}
	
	public static void reverse(int nums[], int i, int j) {
		while (i < j) {
			swap(nums, i++, j--);
		}
	}
	
	public static void swap(int nums[], int x, int y) {
		int temp = nums[x];
		nums[x] = nums[y];
		nums[y] = temp;
	}

}
