import java.util.Scanner;

import javax.lang.model.util.ElementScanner14;

class Logic 
{
    public static boolean Liner_Searh(int[]A,int target)
    {
      int i=0;
      while(i<A.length && A[i]!=target)
        i++;
      
        if(i<A.length)
        
            return true;
        else
            return false;

      }
         

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter How many Elements:");
        int n=sc.nextInt();
        int[]A=new int[n];
       System.out.println("Enter Digits:");
        for(int i=0;i<A.length;i++)
        A[i]=sc.nextInt();
        System.out.println("Enter Target");
        int target=sc.nextInt();
    System.out.println(Liner_Searh(A, target));
      }
}

 