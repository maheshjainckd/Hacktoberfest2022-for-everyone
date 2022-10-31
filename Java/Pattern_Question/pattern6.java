/*

1
2  3
4  5  6
7  8  9 10

*/



package Patter_Question;
import java.util.*;
public class pattern6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=i;j++){
                System.out.print(count++);
            }
            System.out.println();
        }
    }
    
}
