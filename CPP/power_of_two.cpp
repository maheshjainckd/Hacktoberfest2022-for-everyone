#include<iostream>
using namespace std;

void isPowerOfTwo(int f){
    if((f&(f-1)) == 0){
        cout<<f<<" is a power of 2\n";
    }
    else{
        cout<<f<<" is not a power of 2\n";
    }
    return;
}
int main(){
    int n;
    cout<<"Enter any number :\n";
    cin>>n;
    isPowerOfTwo(n);
    return 0;
}