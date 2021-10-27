
public class PowerOf2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(isPowerofTwo(398));
	}
	
	public static boolean isPowerofTwo(long n){
        int x = 0;
        while((1 << x) <= n) {
            if((1 << x) == n) {
                return true;
            }
            x++;
        }
        return false;
        
    }

}
