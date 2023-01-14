//Find the number of ways in which n frends can single or pair up
#include<iostream>
using namespace std;
int frendsPairing(int n){
    if(n==0 || n==1||n==2){
        return n ;
    }
    return frendsPairing(n-1)+frendsPairing(n-2)*(n-1);
    
}
int main()
{
    cout<<frendsPairing(4)<<endl;
    
    return 0;
}