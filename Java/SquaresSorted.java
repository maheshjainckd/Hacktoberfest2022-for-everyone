public class SquaresSortedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = {-4,-1,0,3,10};
		sortedSquares(nums);
	}
	
	public static int[] sortedSquares(int[] nums) {
        int[] result = new int[nums.length];
        int resultIndex = nums.length - 1;
        int start = 0, end = nums.length - 1;
        while(start < end) {
        	if(Math.abs(nums[start]) > Math.abs(nums[end])) {
        		result[resultIndex--] = nums[start] * nums[start];
        		start++;
        	} else {
        		result[resultIndex--] = nums[end] * nums[end];
        		end--;
        	}
        }
		return result;
    }

}
