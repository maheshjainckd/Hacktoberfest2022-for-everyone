

public class PowXN {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(myPow(2.0000, -2147483648));
	}
	
	public static double myPow(double x, int n) {
		long power = n;
		if(power < 0) {
			power = -1 * power;
		}
		double ans = 1.0;
		while(power > 0) {
			if(power % 2 == 0) {
				x = x * x;
				power = power / 2;
			} else {
				ans = ans * x;
				power = power - 1;
			}
		}
		ans = n > 0 ? ans : 1 / ans;
		return ans;
        
    }

}
