
/* We will be solving this using XOR (^)
 * 
 * n ^ 0 = n
 * n ^ n = 0
 * set_bit_in_XOR = XOR & ~(XOR - 1)*/
public class UniqueNumbers {

	public static void main(String[] args) {
		int arr[] = {2, 4, 7, 9, 2, 4};
		int newArray[] = singleNumber(arr);
		for(int i:newArray)
			System.out.println(i);
	}
	
	public static int[] singleNumber(int[] nums)
    {
		int xor = 0;
		
		// XOR with all the elements
		for(int i: nums) {
			xor = xor^i;
		}
		// Set the set bit
		int set_bit = xor & ~(xor - 1);
		// Set the 2 numbers to XOR
		int num_1 = xor;
		int num_2 = xor;
		
		for(int i: nums) {
			if((set_bit & i) > 0) {
				num_1 = num_1^i;
			} else {
				num_2 = num_2^i;
			}
		}
		int newArray[] = new int[2];
		if(num_2 > num_1) {
		    newArray[0] = num_2;
		    newArray[1] = num_1;
		}
		else {
		    newArray[1] = num_2;
		    newArray[0] = num_1;
		}
		return newArray;
    }

}
