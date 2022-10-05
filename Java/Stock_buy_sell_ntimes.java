class Solution {
    public int maxProfit(int[] arr) {
        int n=arr.length;
        int min=Integer.MAX_VALUE;
        int res=0;
        
        for(int i=0;i<n;i++){
            min=Math.min(min,arr[i]);
            if(res<arr[i]-min)
                res=arr[i]-min;
        }
        return res;
    }
}