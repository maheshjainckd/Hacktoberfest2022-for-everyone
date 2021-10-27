
public class LargestSumContiguousPrimeNumbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = {2,5,3,9,4,5,7,11,3,6,1};
		System.out.println(primeNumberSum(arr,arr.length));
	}
	

	static int primeNumberSum(int a[],int size)
	{
	     
	    int max_so_far = a[0], max_ending_here = 0;
	 
	    for (int i = 0; i < size; i++)
	    {
	        if(isPrime(a[i])) {
	        	max_ending_here = max_ending_here + a[i];
		        if (max_ending_here < 0)
		            max_ending_here = 0;
		         
		        else if (max_so_far < max_ending_here)
		            max_so_far = max_ending_here;
	        } else {

	            max_ending_here = 0;
	        }
	         
	    }
	    return max_so_far;
	}
	
	static boolean isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
  
        return true;
    }
}