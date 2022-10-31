//Printing nth fibonacci number
#include<iostream>
using namespace std;
int fibonacci(int n ){
    if(n==0||n==1){  //base condition if n==0 then return 0 if n==1 then retunr 1

        return n ;
    }
    
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    cout<<fibonacci(n)<<endl;
    
    return 0;
}