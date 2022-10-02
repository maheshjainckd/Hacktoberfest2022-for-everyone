// Q .You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9),
//  and some empty cells (denoted by 0).You need to find whether there exists
//  a way to fill all the empty cells with some digit(1 - 9) such that the final 
//  matrix is a valid Sudoku solution.


// Hashing can be also used to implement is valid function
// int row[9][9]={0},col[9][9]={0},square[9][9]={0};for square k=i/3*3+j/3;
// or use this function as follow

bool isvalid(int matrix[][9],int row,int col,int digit){
    for(int i=0;i<9;i++){
        if(matrix[i][col]==digit)
            return false;
        if(matrix[row][i]==digit)
            return false;
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==digit)
            return false;
    }
    return true;
}
//basically it using recursion to check if it is possible to fill a empty cell
//  and again use recursion to check and fill next empty cell 

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]!=0)continue;
            for(int k=1;k<=9;k++){
                if(isvalid(matrix,i,j,k)){
                     matrix[i][j]=k;
                    if(isItSudoku(matrix))
                         return true;
                    else
                        matrix[i][j]=0;
                }                   
            }
            return false;        
        }
    }
    return true;
}

