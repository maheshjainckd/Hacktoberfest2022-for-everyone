//calculate n raised to power of p
#include<iostream>
using namespace std;
int power(int n,int p){
    if(p==0){
        return 1;
    }
    int prevPower=power(n,p-1);
    return n*prevPower;
}
int main()
{
    int n,p;
    cout<<"Enter n";
    cin>>n;
    cout<<"enter p";
    cin>>p;
    cout<<power(n,p)<<endl;

    
    return 0;
}