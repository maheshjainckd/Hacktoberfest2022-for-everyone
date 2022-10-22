#include<iostream>
#include<climits>
using namespace std;

bool isFeasible(int arr[],int n,int m,int mid){
    int painters=1,sum=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i]>mid){
            painters+=1;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    return painters<=m;
}
int maxof(int arr[],int n){
    int max=-1;
    for(int i=0;i<n;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int sumof(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int PaintersPartition(int arr[],int n,int m){
    int mi=maxof(arr,n);
    int ma=sumof(arr,n);
    int result=INT_MAX;
    while(mi<=ma){
        int mid=(mi+ma)/2;
        if(isFeasible(arr,n,m,mid)){
            result=min(result,mid);
            ma=mid-1;
        }
        else{
            mi=mid+1;
        }
    }
    return result;
}
int main(){
    int arr[]={10,20,30,40};
    int n=4;
    int m=2;
    cout<<PaintersPartition(arr,n,m);
    return 0;
}