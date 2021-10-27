// Given an array of size N, K=3, find the maximum sum of subarray of size K

//using optimal approach : Sliding Window Algorithm

public class slidingWindowSum {
    public static void main(String[] args) {
        int[] arr ={4, 1, 3, 2, 5, 4, 7};
        int N= arr.length;
        int K =3;
        int res = maximum(arr, N, K);
        System.out.println(res);
    }
    static int maximum(int[] arr , int N ,int  K){
        int maxsum=0;
        int sum = 0;
        for(int i=0; i<K; i++){
            
            sum += arr[i];
        }
            for(int j=K; j<N; j++){
                sum += (arr[j] - arr[j-K]);
            }
            if(sum>maxsum){
                maxsum = sum;
            }
            
        
        return maxsum;
    }
}
