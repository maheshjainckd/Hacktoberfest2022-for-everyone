import java.util.Scanner;

public class largestNumber {

	public static int[] TakeInput() {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++){
			System.out.println("enter"+i+"elments : ");
			arr[i]=sc.nextInt();
		}
		return arr;
	}
	public static int largest(int[] arr){
		int max=Integer.MIN_VALUE;
		int n=arr.length;
		for(int i=0;i<n;i++){
			if(arr[i]>max){
				max=arr[i];
			}
		}
		return max;
	}
	public static void main(String[] args){
		int[] arr=TakeInput();
		int larg=largest(arr);
		System.out.println(larg);
	}

}
