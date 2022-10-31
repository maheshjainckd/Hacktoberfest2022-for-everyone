
/*
 

0
1  1
2  3  5
8  13 21 34


 */

package Patter_Question;
import java.util.*;
public class pattern10 {
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int a = 0;
    int b = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            int temp;
            System.out.print(a+"\t");
            temp = a+b;
            a = b;
            b = temp;
        }
        System.out.println();
    }


}    
}
