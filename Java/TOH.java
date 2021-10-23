package com.company;

public class TOH {
    static void tower(int n,char A,char B,char C){
        if(n==1) {
            System.out.println("move 1 from " + A + "to" + C);
            return;
        }
        tower(n-1,A,C,B);
        System.out.println("move "+n+" from "+A+"to"+C);
        tower(n-1,B,A,C);

    }
    static int jos(int a,int b){
        if (a==1)
            return 0;
        return (jos(a-1,b)+b)%a;
    }
    public static void main(String[] args) {
        System.out.println(jos(8,3));


    }
}
