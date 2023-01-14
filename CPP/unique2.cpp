#include<iostream>
using namespace std;
int setBit(int n,int pos){
    return ((n&(1<<pos))!=0);

}
int unique(int arr[],int n){

int xorsum=0;
for(int i=0;i<n;i++){

    xorsum=xorsum^arr[i];
    int setbit=0;
    int pos=0;
    whiel(setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >>1;

    }
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newxor=newxor^arr[i];

        }
    }
    cout<<newxor<<endl;
    cpot<<tempxor^<<endl;

}


}
int main(){

    int arr{1,2,2,3,5,9,};
    unique(arr,8);
    



return 0;
}