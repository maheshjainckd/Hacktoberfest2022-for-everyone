
public class CountSetBits {

	public static void main(String[] args) {
		int n = 9;
		System.out.println(hammingWeight(n));
	}
	
	public static int hammingWeight(int n) {
        int count = 0;
        while(n > 0) {
        	count += n & 1;					// If the last bit is one then count is increased
        	n>>=1;							// This means n = n >> 1;
        }
        return count;
    }

}
