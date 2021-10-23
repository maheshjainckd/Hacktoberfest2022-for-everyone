package com.company;

public class Gdc {
    static int ggc(int a,int b){
        int c=Math.min(a, b);
        while (c>0) {
            if (a % c == 0 && b % c == 0) {
                break;

            }
            c--;
        }
        return (a*b)/c;
    }
    public static void main(String[] args) {

        System.out.println(ggc(10,15));

    }
}
