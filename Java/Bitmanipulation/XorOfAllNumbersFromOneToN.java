import java.util.Scanner;

public class XorOfAllNumbersFromOneToN {

	public static void main(String[] args) {
		Scanner sc=new Scanner (System.in);
		int n=sc.nextInt();
		int val=xor(n);
		System.out.println(val);
	}

//	  XOR OF ALL THE NUMBER FROM 1 to N  in constant time 0(1)
	private static int xor(int n) {
		if(n % 4 == 1)return 1;
		if(n % 4 == 2)return (n+1);
		if(n % 4 == 3)return 0;
		if(n % 4 == 0)return n;
		return -1;	
	}
	// XOR of elements even number of times is zero  6
//    N                 XOR
//    1                  1(0 ^ 1)
//    2                  3(1 ^ 2)
//    3                  0(3 ^ 3)
//    4                  4(0 ^ 4)
//    5                  1(4 ^ 5)
//    6                  7(5 ^ 6)
//    7                  0(7 ^ 7)
//    8                  4(0 ^ 8)
}
