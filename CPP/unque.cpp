#include<iostream>
using namespace std;
int unique(int arr[],int n){

    int xorsum=0;
    for(int i=0;i<n;i++){

        xorsum = xorsum^arr[i];
    }
    return xorsum;
}
int main(){
    int arr{1,5, 7,4, 7, 9,};
    cout<<unique(arr,7)<<endl;

return 0;
}