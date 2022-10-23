/*

    1
  2 3 2
3 4 5 4 3
  2 3 2
    1 

*/

package Patter_Question;

import java.util.*;

public class pattern13 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num = 1;
        int count = 1;
        int space = n / 2;
        for (int i = 1; i <= n; i++) {
            int value = count;
            for (int j = 1; j <= space; j++) {
                System.out.print("\t");
            }
            for (int j = 1; j <= num; j++) {
                System.out.print(value + "\t");
                if (j <= num / 2) {
                    value++;
                } else {
                    value--;
                }
            }
            if (i <= n / 2) {
                space--;
                num += 2;
                count++;
            } else {
                space++;
                num -= 2;
                count--;
            }
            System.out.println();

        }
    }
}
