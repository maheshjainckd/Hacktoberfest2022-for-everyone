import java.util.Scanner;
public class palindrome_checker {
    public static void main(String[] args) {
        String name;

        System.out.println("Enter the name");
        Scanner obj = new Scanner(System.in);
        name= obj.nextLine();

        int len = name.length();
        char ch[] = name.toCharArray();

        for(int i=0;i<len/2;i++){
            if(ch[i]!=ch[len-i-1]){
                System.out.println("Not a Palindrome");
                System.exit(0);

            }


        }
        System.out.println("Palindrome");


    }

}
