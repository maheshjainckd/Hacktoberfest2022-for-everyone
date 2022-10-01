//Kadanes Algorithm
//Maximum sum subarray
import java.util.* ;
public class Kadanes {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in) ;
		System.out.println("enter size of array :");
		int sz = in.nextInt();
		int a[] = new int[sz] ;
		for(int i=0 ; i<sz ; i++)
		{
			System.out.println("enter :");
			a[i] = in.nextInt();
		}
		
		
		int current_max=a[0] ;
		int global_max=a[0] ;
		for(int i=1 ; i<sz ; i++)
		{
			current_max = Math.max(a[i], current_max+a[i]) ;
			if(current_max > global_max)
				global_max = current_max ;
		}
		System.out.println("Maximum subarray sum :"+global_max);
		
	}
}