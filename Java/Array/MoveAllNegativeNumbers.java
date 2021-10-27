import java.util.Scanner;

public class MoveAllNegativeNumbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int arraySize = sc.nextInt();
		int arr[] = new int[arraySize];
		for(int j = 0; j < arraySize; j++) {
			arr[j] = sc.nextInt();
		}
		rearrange(arr,arraySize);
		printArray(arr,arraySize);
	}

	private static void rearrange(int[] arr, int arraySize) {

		int j = 0;
		for(int i = 0; i < arraySize; i++) {
			if(arr[i] < 0) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				j++;
			}
		}
		
	}
 
    static void printArray(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }

}
