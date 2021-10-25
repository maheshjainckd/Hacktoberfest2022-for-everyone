import java.util.Arrays;
public class InsertionSort {
    public static void main(String[] args) {
        int[] arr = { 5, 4, 3, 2, 1 };
        System.out.println("The unsorted array is " + Arrays.toString(arr));
        insertion(arr);
        System.out.println("The sorted array is " + Arrays.toString(arr));
    }

    public static void insertion(int[] arr) {
        for(int i=0;i < arr.length - 1;i++){
            for(int j=i+1;j>0;j--){
                if(arr[j] < arr[j-1]){
                    swap(arr, j, j-1);
                }else{
                    break;
                }
            }
        }
    }

    public static void swap(int[] arr,int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
