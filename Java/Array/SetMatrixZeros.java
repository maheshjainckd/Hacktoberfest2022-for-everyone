

import java.util.Arrays;

public class SetMatrixZeros {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int matrix[][] = {{1,1,1},{1,0,1},{1,0,1}};
		setZeroes(matrix);
		
	}
	
	public static void setZeroes(int[][] matrix) {
		int col[] = new int[matrix[0].length];
		int row[] = new int[matrix.length];
        Arrays.fill(col, -1);
        Arrays.fill(row, -1);
		for(int i = 0; i < matrix.length; i++) {
			for(int j = 0; j < matrix[i].length; j++) {
				if(matrix[i][j] == 0) {
					row[i] = 0;
					col[j] = 0;
				}
			}
		}
		for(int i = 0; i < matrix.length; i++) {
			for(int j = 0; j < matrix[i].length; j++) {
				if((row[i] == 0) || col[j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
        
    }

}
