public class TrappingRainWater {
    public int trap(int[] height) {
        int n = height.length;
        int i=0, j = n-1, lmax =0, rmax=0, r=0;
        
        while(i<=j){
            // find the smaller height
            if(height[i]<=height[j]){
                if(height[i]<lmax){
                    r = r +(lmax-height[i]);
                }
                else
                    lmax = height[i];
                    i++;
            }
            else{
                 if(height[j]<rmax){
                    r = r +(rmax-height[j]);
                }
                else
                    rmax = height[j];
                    j--;
                
            }
        }
        return r;
    }
}
