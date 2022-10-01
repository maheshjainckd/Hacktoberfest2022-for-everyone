class Solution {
     public boolean isRow0(int[][] mat, int row){
             for(int col=0;col<mat[0].length;col++){
                 if(mat[row][col]==0) return true;
             }
         return false;
         }
    public boolean isCol0(int[][] mat, int col){
             for(int row=0;row<mat.length;row++){
                 if(mat[row][col]==0) return true;
             }
         return false;
         }
    public void setZeroes(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;
        
        int[][] copy = new int [rows][cols];
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                copy[row][col] = mat[row][col];
                if(isRow0(mat,row)==true || isCol0(mat,col)==true){
                    copy[row][col] = 0;
                }
            }
        }
        for(int row =0;row<rows;row++){
            for(int col=0;col<cols;col++){
                mat[row][col] =copy[row][col];
            }
        }
    }
}
