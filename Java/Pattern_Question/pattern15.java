/*

1                       1
1 2                   2 1 
1 2 3               3 2 1 
1 2 3 4           4 3 2 1
1 2 3 4 5       5 4 3 2 1 
1 2 3 4 5 6   6 5 4 3 2 1 
1 2 3 4 5 6 7 6 5 4 3 2 1 

*/

package Patter_Question;

import java.util.*;

public class pattern15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 1;
        int innerSpace = 2 * n - 3;
        for (int i = 1; i <= n; i++) {
            int value = 1;
            for (int j = 1; j <= count; j++) {
                System.out.print(value + "\t");
                value++;
            }
            for (int j = 1; j <= innerSpace; j++) {
                System.out.print("\t");
            }
            if (i == n) {
                count--;
                value--;
            }
            for (int j = 1; j <= count; j++) {
                value--;
                System.out.print(value + "\t");
            }
            if (i <= n) {
                innerSpace -= 2;
                count++;
            } else {
                innerSpace += 2;
                count--;
            }
            System.out.println();

        }
    }
}
