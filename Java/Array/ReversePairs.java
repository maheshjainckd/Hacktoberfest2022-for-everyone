
import java.util.ArrayList;
import java.util.List;

public class ReversePairs {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nums[] = {1,3,2,3,1};
		System.out.println(reversePairs(nums));
	}
	
	public static int reversePairs(int[] nums) {
		return mergeSort(nums, 0, nums.length-1);
        
    }
	
	static int mergeSort(int nums[], int low, int high) {
		if(low>=high) return 0;
		int mid = (low + high) / 2;
		int reverseCount = mergeSort(nums, low, mid);
		reverseCount += mergeSort(nums, mid+1, high);
		reverseCount += merge(nums, low, mid, high);
		return reverseCount;
	}

	private static int merge(int[] nums, int low, int mid, int high) {
		int j = mid+1;
		int count = 0;
		for(int i = low; i <= mid; i++) {
			while(j<=high && (nums[i] > (2 * (long) nums[j]))) {
				j++;
			}
			count += (j - (mid + 1));
		}
		
		List<Integer> temp = new ArrayList<>();
		int left = low, right = mid+1;
		while(left<=mid && right<=high) {
			if(nums[left] <= nums[right]) {
				temp.add(nums[left]);
				left++;
			} else {
				temp.add(nums[right]);
				right++;
			}
		}
		while(left<=mid) {
			temp.add(nums[left]);
			left++;
		}
		while(right<=high) {
			temp.add(nums[right]);
			right++;
		}
		for(int i = low; i <= high; i++) {
			nums[i] = temp.get(i - low);
		}
		return count;
	}

}
