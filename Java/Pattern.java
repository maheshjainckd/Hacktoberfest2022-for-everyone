import java.util.Iterator;

public class pattern {
	public static void main(String[] args) {
		pattern3(5);
	}
	
    static void pattern2(int n){
		for(int row = 0; row <= n; row++) {
			 //for every row, run the col
			for (int col = 0; col <= n; col++) {
				System.out.print("* ");
			}
			//when one row is printed,add new line
			System.out.println();
		}
	}
    
	static void pattern6(int n) {
		for(int row = 0; row <= 2*n; row++) {
			int totalcolsinrow = row > n ? 2 *n - row :row;
			
			int noOfSpaces = n - totalcolsinrow;
			for(int s = 0; s < noOfSpaces; s++) {
				System.out.print(" ");
			}
			for(int col = 0; col<totalcolsinrow ; col++) {
				System.out.print("* ");
			}
			System.out.println();
		}
	}
	
	static void pattern5(int n) {
		for(int row = 0; row <= 2*n; row++) {
			int totalcolsinrow = row > n ? 2 *n - row :row;
			for(int col = 0; col<totalcolsinrow ; col++) {
				System.out.print("* ");
			}
			System.out.println();
		}
	}
	
	static void pattern4(int n){
		for(int row = 0; row <= n; row++) {
			 //for every row, run the col
			for (int col = 0; col <= row; col++) {
				System.out.print(col+" ");
			}
			//when one row is printed,add new line
			System.out.println();
		}
	}
	
	static void pattern3(int n){
		for(int row = 0; row <= n; row++) {
			 //for every row, run the col
			for (int col = 0; col <= n-row; col++) {
				System.out.print("* ");
			} 
			//when one row is printed,add new line
			System.out.println();
		}
	}
	
	static void pattern1(int n){
		for(int row = 0; row <= n; row++) {
			 //for every row, run the col
			for (int col = 0; col <= row; col++) {
				System.out.print("* ");
			}
			//when one row is printed,add new line
			System.out.println();
		}
	}
}