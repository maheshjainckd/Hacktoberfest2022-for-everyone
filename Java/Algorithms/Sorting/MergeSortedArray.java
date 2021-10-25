class MergeSortedArray {
    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int[] nums2 = {2, 5, 6};
        //merge(nums1, 3, nums2, 3);
        mergeArray(nums1, 3, nums2, 3);
        for (int i = 0; i < nums1.length; i++) {
            System.out.print(nums1[i] + " ");
        }
    
    }

    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        //make a new array to get the answer
         int[] result = new int[m + n];
         //beginning from both head
         int i = 0, j = 0, temp;
         while (i < m || j < n) {
           if (i == m) {
             //if nums1 is ending just copy the nums2
             temp = nums2[j++];
           } else if (j == n) {
             //if nums2 is ending just copy the nums1
             temp = nums1[i++];
           } else if (nums1[i] < nums2[j]) {
             //copy the smaller number
             temp = nums1[i++];
           } else {
             temp = nums2[j++];
           }
           result[i + j - 1] = temp;
         }
         //copy the answer to the nums1
         for (int length = 0; length < n + m; length++) {
           nums1[length] = result[length];
         }
     }
     // Alternate approach
     public static void mergeArray(int[] nums1, int m, int[] nums2, int n) {
        int p1 = m-1, p2=n-1, i = m+n-1;
        while(p2>=0){
            if(p1>=0 && nums1[p1]>nums2[p2]){
                nums1[i--] = nums1[p1--];
            }else{
                nums1[i--] = nums2[p2--];
            }
        }
     }
}