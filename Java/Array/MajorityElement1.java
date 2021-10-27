

public class MajorityElement1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = {2,2,1,1,1,2,2};
		System.out.println(majorityElement(nums));
	}
	public static int majorityElement(int[] nums) {
		int count = 0;
		int element = -1;
		for(int i: nums) {
			if(count==0) {
				element = i;
			}
			if(element == i) {
				count++;
			} else {
				count--;
			}
		}
		return element;
        
    }

}
