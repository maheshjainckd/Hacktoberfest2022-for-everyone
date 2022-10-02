#include<iostream>
using namespace std;

int gcd (int a , int b ) {
    if(a ==0 ) {
        return a;
    }
    if(b==0) {
        return b;
    }

    while( a != b) {
        if(a > b) {
            a=a-b;
        }
        else{
            b=b-a;
        }

    }
    return a;
}

  int main(){
    int a ; 
    int b;
    cout<<"Enter no a: "<<endl;
    cin>>a;
    cout<<"Enter no b: "<<endl;
    cin>>b;
    
    int ans = gcd(a , b);
    cout<<"The gcd of " <<a << " & "<<b <<" is "<< ans;
  
  return 0;
 }