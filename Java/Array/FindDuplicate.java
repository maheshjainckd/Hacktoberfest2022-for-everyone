import java.util.*;

public class FindDuplicate {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nums[] = {1,3,4,2,2};
		System.out.println(findDuplicate(nums));
	}
	
	 public static int findDuplicate(int[] nums) {
		// Keep 2 pointer fast and slow at the initial index
		int fast = nums[0];
		int slow = nums[0];
		// Keep moving the pointers until their 1st collision
		do {
			// fast goes 2 steps at a time
			fast = nums[nums[fast]];
			// slow goes 1 steps at a time
			slow = nums[slow];
		} while(fast != slow);
		// Once they collide bring the fast pointer again to the initial position
		fast = nums[0];
		// Keep moving the pointers until their 2nd collision and thats the duplicate number
		while(fast != slow) {
			// Now fast goes 1 steps at a time
			fast = nums[fast];
			slow = nums[slow];
		}
		// Return either fast or slow pointer
		return slow;
	 }

}
