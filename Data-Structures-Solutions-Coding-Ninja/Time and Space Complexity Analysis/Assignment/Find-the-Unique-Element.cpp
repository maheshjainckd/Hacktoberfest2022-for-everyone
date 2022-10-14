// Find the Unique Element
int findUnique(int *arr, int n) {
    // Write your code here
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    return ans;
}