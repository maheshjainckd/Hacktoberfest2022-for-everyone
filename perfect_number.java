import java.util.*;
public class perfect_number {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt();
        int i,sum=0;
        for(i=1; i<x; i++)
        {
            if(x%i==0)
            {
               sum=sum+i;
            }
        }
        if(x==sum)
        {
            System.out.println("Perfect Number");
        }
        else
        {
            System.out.println("Not a perfect Number");
        }
    }
}
