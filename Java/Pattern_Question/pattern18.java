/*

*  *  *  *  *  *  *
   *           *
      *     *
      *  *  *
   *  *  *  *  *
*  *  *  *  *  *  *   

*/

package Patter_Question;

import java.util.*;

public class pattern18 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int innerSpace = 0;
        int star = n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= innerSpace; j++) {
                System.out.print("\t");
            }
            for (int j = 1; j <= star; j++) {
                if (i > 1 && i <= n / 2 && j > 1 && j < star) {
                    System.out.print("\t");
                } else {
                    System.out.print("*\t");
                }

            }
            if (i <= n / 2) {
                star -= 2;
                innerSpace++;
            } else {
                star += 2;
                innerSpace--;
            }
            System.out.println();
        }

    }
}
