// Triplet sum
#include<bits/stdc++.h>
int pairSum(int arr[], int i,int j, int num)
{
    int count=0;
    while(i<j){
        if(arr[i]+arr[j]==num){
            // count++;
            if(arr[i]==arr[j])
            {
                int n=j-i+1;
                count+=(n*(n-1))/2;
                return count;
            }
            
            int index1=i+1;
            int index2=j-1;
            while(index1<=index2&&arr[index1]==arr[i]){
                // cout<<i<<" "<<j<<endl;
                //counti++;
                index1++;
            }
            while(index1<=index2&&arr[index2]==arr[j]){
                // cout<<i<<" "<<j<<endl;
                //countj++;
                index2--;
            }
           int c1=index1-i;
            int c2=j-index2;
            
            count=count+c1*c2;
            i=index1;
            j=index2;
            
        }
        else if(arr[i]+arr[j]>num){
            j--;
        }
        else{
            i++;
        }
    }
    return count;
}
int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr,arr+n);
    int count=0;
    for(int i=0;i<n-2;i++){
        // cout<<n-i-1<<" "<<num-arr[i]<<endl;
        int count2=pairSum(arr,i+1,n-1,num-arr[i]);
        count =count+count2;
    }
    return count;
}