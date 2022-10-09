//Print numbers till n in decreaseing order
#include<iostream>
using namespace std;
void dec(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
//Print the numbers till n in increaseing order
void inc(int n){
   if(n==1){
        cout<<"1"<<endl;
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}
int main()
{
    int n;
    cin>>n;
    // dec(n);
    inc(n);

    return 0;
}