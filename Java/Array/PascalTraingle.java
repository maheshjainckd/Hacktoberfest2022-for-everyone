
import java.util.*;

public class PascalTraingle {
	public static void main(String args[]) {
		System.out.println(generate(5));
	}
	public static List<List<Integer>> generate(int numRows) {
		List<List<Integer>> traingle = new ArrayList<List<Integer>>();
		List<Integer> currentRow, previousRow = null;
		for(int i = 0 ; i < numRows; i++) {
			currentRow = new ArrayList<Integer>();
			/* Since we know that the number of columns in each row 
			 * would be equal to the number of rows so we traverse till the row count*/
			for(int j = 0; j <= i; j++) {
				if(j==0 || j==i) {
					// First and last element in row will be 1
					currentRow.add(1);
				}
				else {
					// Inner elements will be the sum of previous row j-1 and j
					currentRow.add(previousRow.get(j-1) + previousRow.get(j));
				}
					
			}
			previousRow = currentRow;
			traingle.add(currentRow);
			
		}
		return traingle;
        
    }
}
