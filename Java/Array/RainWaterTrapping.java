
public class RainWaterTrapping {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[] = { 3, 1, 2, 4, 0, 1, 3, 2 };
		
		System.out.println(trap(a));
	}
	
	public static int trap(int[] height) 
	{
		int count = 0;
		int left[] = new int[height.length];
		int right[] = new int[height.length];
		
		for(int i = 0; i < height.length; i++) {
			if(i == 0) {
				left[i] = height[i];
			} else {
				if(left[i-1] < height[i]) {
					left[i] = height[i];
				} else {
					left[i] = left[i-1];
				}
			}
		}
		for(int i = height.length - 1; i >= 0; i--) {
			if(i == height.length - 1) {
				right[i] = height[i];
			} else {
				if(right[i+1] < height[i]) {
					right[i] = height[i];
				} else {
					right[i] = right[i+1];
				}
			}
		}
		for(int i = 0; i < height.length; i++) {
			int trappedWater = Math.min(left[i], right[i]) - height[i];
			count += trappedWater;
		}
		return count;
        
    }

}
