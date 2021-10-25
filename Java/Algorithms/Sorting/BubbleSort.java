import java.util.Arrays;

class BubbleSort {
    public static void main(String[] args) {
        int[] arr = { 5,4,3,2,1 };
        System.out.println("The unsorted array is : " + Arrays.toString(arr));
        bubble(arr);
        System.out.println("The sorted array is : " + Arrays.toString(arr));
    }

    public static void bubble(int[] arr) {
        boolean swapped;
        for (int i = 0; i < arr.length - 1; i++) {
            swapped = false;
            for (int j = 1; j < arr.length - i; j++) {
                // swap
                if (arr[j] < arr[j - 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    swapped = true;
                }
            }
            // if not swapped the array is sorted so break out of the loop
            if(!swapped){
                break;
            }
        }
    }
}