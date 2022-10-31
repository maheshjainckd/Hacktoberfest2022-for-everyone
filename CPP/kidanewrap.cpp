#include<iostream>
#include<climits>
using namespace std;

int kaden (int arr[],int n){


 int currsum=0;
 int maxsum=INT_MIN;

for(int i=0;i<n;i++){

   currsum+=arr[i];
   if(currsum<0){

       currsum=0;
   }
   maxsum=max(maxsum,currsum);
    }
return maxsum;
}
int main(){
int n;
cin>>n;


int arr[n];
for(int i=0;i<n;i++){

    cin>>arr[i];
    }
    int wrap;
    int nonwrap;
    int totalsum;
    nonwrap=kaden(arr,n);
    for(int i=0;i<n;i++){

     totalsum+=arr[i];
    arr[i]=-arr[i];
    }
wrap=totalsum+kaden(arr,n);
cout<<max(wrap,nonwrap)<<endl;

return 0;
}