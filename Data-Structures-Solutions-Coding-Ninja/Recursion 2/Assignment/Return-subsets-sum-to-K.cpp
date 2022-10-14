// Return subsets sum to K
#include<iostream>
using namespace std;
int helper(int input[], int n, int output[][50], int k,int start) {
    // Write your code here
    if(k==0){
        output[start][0]=0;
        return start+1;
    }
    if(n==0){
        return start;
    }
    int smallOutput=helper(input,n-1,output,k,start);
    int count=smallOutput;
    if(k-input[n-1]>=0){
        int smallOutput2=helper(input,n-1,output,k-input[n-1],smallOutput);
        for(int i=smallOutput;i<smallOutput2;i++){
            int index=output[i][0]+1;
            output[i][index]=input[n-1];
            output[i][0]=output[i][0]+1;
        }
        return smallOutput2;
    }
    else{
        return smallOutput;
    }
    
}
int subsetSumToK(int input[], int n, int output[][50], int k) {
    int ans=helper(input,n,output,k,0);
    // cout<<ans<<endl;
    return ans;
}
