import java.util.*;

// import java.util.Scanner;
public class _17FibonacciRecursion {
	public static int fibRecursion(int count) {
		if (count == 0) {
			return 0;
		}
		
		if (count == 1 || count == 2) {
			return 1;
		}
		
		return fibRecursion(count - 1) + fibRecursion(count - 2);
	}

	public static void main(String[] args) {
		
		Scanner reader = new Scanner(System.in);
		
		int fib_len ;
		System.out.println("How many number do you want to print : ");
		fib_len = reader.nextInt();
		
		System.out.print("Fibonacci Series of " + fib_len + " number is: \n");
		
		for(int i = 0; i < fib_len; i++) {
			System.out.print(fibRecursion(i) + " ");
		}
		
		reader.close();
	}
}