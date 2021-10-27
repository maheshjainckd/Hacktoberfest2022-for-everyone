
import java.util.*;

public class MajorityElement2 {

	public static void main(String args[]) {
		int nums[] = {3,2,3};
		System.out.println(majorityElement(nums));
	}
	
	public static List<Integer> majorityElement(int[] nums) {
		List<Integer> elements = new ArrayList<Integer>();
		int count1 = 0;
		int element1 = Integer.MIN_VALUE;
		int count2 = 0;
		int element2 = Integer.MIN_VALUE;
		for(int i: nums) {
			if(i == element1) {
				count1++;
			} else if(i == element2) {
				count2++;
			} else if(count1 == 0) {
				element1 = i;
				count1 = 1;
			} else if(count2 == 0) {
				element2 = i;
				count2 = 1;
			} else {
				count1--;
				count2--;
			}
		}
		count1 = 0;
		count2 = 0;
		int majority = nums.length / 3;
		for(int i: nums) {
			if(element1 == i) {
				count1++;
			}
			if(element2 == i) {
				count2++;
			}
		}
		if(count1 > majority) {
			elements.add(element1);
		}
		if(count2 > majority) {
			elements.add(element2);
		}
		return elements;
        
    }
}
