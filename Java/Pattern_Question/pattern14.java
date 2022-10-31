/*

     *
  *     *
*         *
  *     *
     *   

*/

package Patter_Question;

import java.util.*;

public class pattern14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int innerSpace = -1;
        int outerSpace = n / 2;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= outerSpace; j++) {
                System.out.print("\t");
            }
            System.out.print("*\t");
            for (int j = 1; j <= innerSpace; j++) {
                System.out.print("\t");
            }
            if (i > 1 && i < n) {
                System.out.print("*\t");
            }
            if (i <= n / 2) {
                outerSpace--;
                innerSpace += 2;
            } else {
                outerSpace++;
                innerSpace -= 2;
            }
            System.out.println();
        }
    }
}
