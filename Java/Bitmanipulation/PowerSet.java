
import java.util.ArrayList;
import java.util.List;

public class PowerSet {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(AllPossibleStrings("abc"));
	}
	
	public static List<String> AllPossibleStrings(String s)
    {
		int n = s.length();
		List<String> a= new ArrayList<>();
		for (int i = 0; i < n; i++) {
	           
            // 2nd for loop is for selection
            // of ending point
            for (int j = i; j < n; j++) {
               
                // 3rd loop is for printing from
                // starting point to ending point
                for (int k = i; k <= j; k++) {
                    System.out.print(s.charAt(k));
                }
               
                // changing the line after printing
                // from starting point to ending point
                System.out.println();
            }
        }
        // Code here
        return a;
    }

}
