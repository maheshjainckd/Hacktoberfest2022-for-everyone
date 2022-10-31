/* 

        *
      * *
    * * *
  * * * *
* * * * *

*/


package Patter_Question;
import java.util.*;
public class pattern3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int space = n-1;
        int star = 1;
        for(int i = 0;i<n;i++ ){
            for(int j = 0;j<space;j++){
                System.out.print(" ");
            }
            for(int j = 0;j<star;j++){
                System.out.print("*");
            }
            space--;
            star++;
            System.out.println();
        }
        
    }
    
}
