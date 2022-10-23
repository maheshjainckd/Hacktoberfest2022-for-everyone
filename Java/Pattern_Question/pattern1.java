/*

*
* *
* * *
* * * *
* * * * *

*/


package Patter_Question;

import java.util.*;
public class patter1 {
    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=i;j++){
                System.out.print("*");
            }
            System.out.println();
        }

    }
}
