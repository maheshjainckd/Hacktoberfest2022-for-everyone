import java.util.Scanner;

public class linearSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter the size of the array: ");
        int n = sc.nextInt();
        int []marks = new int[n];

        //input loop 
        for(int i=0 ; i<n;i++){
            marks[i]=sc.nextInt();
        }
        System.out.println("Enter the number you want to search: ");
        int number = sc.nextInt();
        //output loop
        for(int j =0;j<n;j++){
            if(marks[j]== number){
                System.out.println("your desired number is at: "+ j + "th place");
            }
        }
    }

}
