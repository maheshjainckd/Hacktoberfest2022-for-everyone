#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

const int N=1e3+10;
static int t[N][N];

bool knapsack(int arr[],int sum,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j == 0){
                t[i][j] = 1;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=sum){
               t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    

    return t[n][sum];
}

int main()
{
    int arr[] = {1,5,7,9};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    //odd sum
    if(sum%2 != 0){
        cout<<0<<endl;
    }
    //even sum
    else{
        int equal_sum = sum/2;
        cout<<knapsack(arr, equal_sum, n)<<endl;
    }
    
    
}