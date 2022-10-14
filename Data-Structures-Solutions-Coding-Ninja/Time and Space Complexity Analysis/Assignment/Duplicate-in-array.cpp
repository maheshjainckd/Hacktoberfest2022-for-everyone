// Duplicate in array
int findDuplicate(int *arr, int n)
{
    //Write your code here
    int ans1=(n-2)*(n-1)/2;
    int ans2=0;
    for(int i=0;i<n;i++){
        ans2=ans2+arr[i];
    }
    return ans2-ans1;
}