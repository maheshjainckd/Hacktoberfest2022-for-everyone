import java.util.*;
class piglatin
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the string");
        String s=sc.nextLine();
        int l=s.length();String k="",y="";int t=0,x=0;
        for(int i=0;i<l;i++)
        {
            char ch=s.charAt(i);
            if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'))
            {
                if(i==0)
                {
                    k=s+"ay";
                    System.out.println(k);
                    break;
                }
                else
                {
                    t++;
                     x=i;
                    break;
                }
            }
        }
        if(t>0)
        {
            k=s.substring(x);
            y=s.substring(0,x);
            System.out.println(k+y+"ay");
        }
    }
}
