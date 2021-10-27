public class sumOfSubarray {
    public static void main(String[] args) {
        int[] arr = {1, -2, 3, 4, -5, 2};
        
        int res = sumarr(arr);
        System.out.println(res);
    }
    static int sumarr(int[] arr){
        int maxSum = 0;
         int sum=0;
        for (int i = 0; i < arr.length; i++) {
            if(sum>=0){
                sum += arr[i];
            }else{
                sum =arr[i];
            }
            if(sum>maxSum){
                maxSum = sum;
            }
            
}
return maxSum;
}
}