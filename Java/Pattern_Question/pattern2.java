/*

* * * * *
* * * *
* * *
* *
*

*/
package Patter_Question;
import java.util.*;
public class patter2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                System.out.print("*");
            }
            System.out.println();
        }
        
    }
    
}
