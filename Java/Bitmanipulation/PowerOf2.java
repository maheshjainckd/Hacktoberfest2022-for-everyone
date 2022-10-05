package bitMagic;

import java.util.Scanner;

public class PowerOf2 {
    static boolean isPowerOfTwo(int n){
        if(n==0)
            return false;
        return ((n&(n-1))==0); //brains kerningam algorithm
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the no you want to check");
        int num =sc.nextInt();
        System.out.println(isPowerOfTwo(num));

    }
}
