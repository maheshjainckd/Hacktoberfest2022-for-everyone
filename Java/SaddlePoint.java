//Java code to find saddle point in a matrix

import java.util.*;
class Test
{
    static boolean findSaddlePoint(int mat[][], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int min_row = mat[i][0], col_ind = 0;
            for (int j = 1; j < n; j++)
            {
                if (min_row > mat[i][j])
                {
                    min_row = mat[i][j];
                    col_ind = j;
                }
            }
      
            int k;
            for (k = 0; k < n; k++)
      
                if (min_row < mat[k][col_ind])
                    break;
      
            if (k == n)
            {
               System.out.println("Value of Saddle Point " + min_row);
               return true;
            }
        }
      
        return false;
    }
     
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int mat[][] = new int[3][3];
        Sytem.out.println("enter 3X3 matrix");
        int n = 3;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            mat[i][j]=sc.nextInt();
            
        }
         
        if (findSaddlePoint(mat, n) == false)
            System.out.println("No Saddle Point ");
    }
}
