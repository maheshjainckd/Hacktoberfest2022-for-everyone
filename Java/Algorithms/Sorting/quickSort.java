// Quick Sort
// Time: O(n*(log n)) -average; 
// Space: O(log n) -stable; O(1) -unstable;
// Quicksort becomes slower [O(n^2)] if already sorted array is given, and the pivot is selected as the rightmost element. So, selecting a random index as pivot is important.
import java.util.Arrays;

public class Main
{
	public static void main(String[] args) {
		int[] nums = {43, 65,2, 5, 4, 98, -6, -34, 1, 11};
		System.out.println(Arrays.toString(nums));
		quickSort(nums, 0, nums.length-1);
		System.out.println(Arrays.toString(nums));
	}
	
	static void quickSort(int[] arr, int start, int end){
	    if (start < end) {
	        // in each pass, pivot is placed at correct (Sorted) index.
	        int pivotindex = partition(arr, start, end);
	        
	        quickSort(arr, start, pivotindex-1);
	        quickSort(arr, pivotindex, end);
	    }
	}
	
	static int partition(int[] arr, int start, int end){
	    int pivot = arr[end];
	    int i = start-1;
	    
	    for (int j = start; j<end; j++) {
	        if (arr[j] <= pivot){
	            i++;
	            swap(arr, i, j);
	        }
	    }
	    swap(arr, i+1, end);
	    return i+1;
	}
	
	static void swap(int[] arr, int i, int j){
	    int temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	}
}
