//calvulate the factorial useing recursion
#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;

    }
    int preFactorial=factorial(n-1);
    return n*preFactorial;

}
int main()
{int n;
cout<<"Enter N\n";
cin>>n;
cout<<factorial(n)<<endl;

    
    return 0;
}