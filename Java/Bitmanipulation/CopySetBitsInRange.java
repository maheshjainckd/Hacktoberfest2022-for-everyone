
public class CopySetBitsInRange {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(setSetBit(20909, 10178, 2, 6));
	}
	
	static long setSetBit(int x, int y, int l, int r){
		int mask = 0;
		for(int i = l; i < r; i++) {
			mask = 1 << i-1; 
			if((y & mask) > 0) {
				x = x | mask; 
			}
		}
		return x;
    }

}
