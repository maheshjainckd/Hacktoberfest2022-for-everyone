public class BubbleSortRecursive {

    public static void main(String[] args) {
        int arr[] = {6, 4, 1, 2, 5};
        sortUsingRecursion(arr, arr.length);
        for(int i=0; i<arr.length; i++) {
            System.out.println(arr[i]);
        }
    }

    public static void sortUsingRecursion(int[] arr, int n) {
        if(n==1){
            return;
        }

        for(int j=0; j<n-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        sortUsingRecursion(arr, n-1);
    }
}