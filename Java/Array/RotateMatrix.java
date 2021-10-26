

public class RotateMatrix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int matrix[][] = {{1,2,3},{4,5,6},{7,8,9}};
		rotate(matrix);
		for(int[] i: matrix) {
			for(int j: i) {
				System.out.print(j+" ");
			}
			System.out.println();
		}
	}
	
	public static void rotate(int[][] matrix) {
        for(int row = 0; row < matrix.length; row++) {
        	/* initialize column with row since we don't want the 
        	 * previous swapped indexs get changed with every row iteration */
        	for(int col = row; col < matrix[row].length; col++) {
        		swap(matrix, row, col);
        	}
        }
        for(int row = 0; row < matrix.length; row++) {
        	for(int col = 0; col < matrix[row].length / 2; col++) {
        		int temp = matrix[row][col];
        		matrix[row][col] = matrix[row][matrix[row].length - 1 - col];
        		matrix[row][matrix[row].length - 1 - col] = temp;
        	}
        }
    }
	
	public static void swap(int[][] matrix, int row, int col) {
		int temp = matrix[row][col];
		matrix[row][col] = matrix[col][row];
		matrix[col][row] = temp;
	}

}
