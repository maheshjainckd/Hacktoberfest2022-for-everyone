
/*

1
1 1
1 2 1
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1

*/
package Patter_Question;

import java.util.Scanner;

public class pattern12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int iCj = 1;
            for (int j = 0; j <= i; j++) {
                System.out.print(iCj + "\t");
                int iCjp1 = iCj * (i - j) / (j + 1);
                iCj = iCjp1;
            }
            System.out.println();
        }
    }
}
