#include <bits/stdc++.h> 
using namespace std;
int dp[1000][1000];
int mcm(int arr[],int i,int j){
    
    if(i>=j){return 0;}
    int min =INT_MAX;
    int temp;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    for(int k=i;k<j;k++){
         temp = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
    }

    if(temp<min){
        min=temp;
    }

    return dp[i][j]=min;

}

int main(){
    memset(dp,-1,sizeof(dp));
    int arr[]={1,2,3,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<mcm(arr,1,n-1);

}