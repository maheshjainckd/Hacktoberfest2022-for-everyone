
public class CountSetBitsFrom1ToN {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 11;
		System.out.println(countSetBits(n));
	}
	
	public static int countSetBits(int n){
		// Base condition
		if(n==0) return 0;
        int x = largestPowerOfTwo(n);
        // Bits upto 2 Raise To The Power Of x
        int bits1 = x * (1 << (x-1));
        // First column bits from 2 raise to the power of x to n
        int bits2 = n - (1 << x) + 1;
        // Rest bits n - 2 raise to the power of x
        int rest = n - (1 << x);
        int count = bits1 + bits2 + countSetBits(rest);
        return count;
    }
	
	public static int largestPowerOfTwo(int n) {
		int x = 0;
		// 2 to the power x should be less than equal to n
		while((1 << x) <= n ) {
			x++;
		}
		
		return x - 1;
	}
     
}
