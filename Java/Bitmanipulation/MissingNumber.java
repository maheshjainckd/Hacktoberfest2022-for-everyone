package bitMagic;

import java.util.Scanner;

public class MissingNumber {

    static int missingNo(int[] a,int n){
        int res=a[0];
        for(int i=1;i<n;i++){
            res=res^a[i];

        }
        for(int i=1;i<=n+1;i++){
            res=res^i;
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the value of the N");
        int n =sc.nextInt();
        int []arr = new int[n];
        System.out.println("enter the value of the array such that the value ranges from 1 to n+1");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("the missing no is "+missingNo(arr,n));
    }
}
