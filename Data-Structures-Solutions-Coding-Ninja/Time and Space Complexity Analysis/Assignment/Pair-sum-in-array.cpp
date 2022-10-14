// Pair sum in array
#include<bits/stdc++.h>
int pairSum(int *arr, int n, int num)
{
	//Write your code here
    int count=0;
    sort(arr,arr+n);
    int i=0;
    int j=n-1;
    if(n<=0){
        return 0;
    }
    if(arr[i]==arr[j] && arr[i]==num/2){
        // cout<<"entered equal"<<endl;
        count=n*(n-1)/2;
        return count;
    }
    while(i<j){
        if(arr[i]+arr[j]==num){
            // count++;
            int counti=1;
            int countj=1;
            while(arr[i]==arr[i+1] && i<j-1){
                // cout<<i<<" "<<j<<endl;
                counti++;
                i++;
            }
            while(arr[j]==arr[j-1] && j>i+1){
                // cout<<i<<" "<<j<<endl;
                countj++;
                j--;
            }
            i++;
            j--;
            count=count+counti*countj;
            
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