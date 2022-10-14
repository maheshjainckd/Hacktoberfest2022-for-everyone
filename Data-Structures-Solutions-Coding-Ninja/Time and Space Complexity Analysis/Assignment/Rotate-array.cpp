// Rotate array
void rotate(int *input, int d, int n)
{
    //Write your code here
    int arr[d];
    for(int i=0;i<d;i++){
        arr[i]=input[i];
    }
    for(int i=0;i<n;i++){
        input[i]=input[i+d];
    }
    int j=0;
    for(int i=n-d;i<n;i++){
        input[i]=arr[j];
        j++;
    }
}