#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<n;++i && n!=2)
    {
        if(n%i==0)
        {
            cout<<"number is not prime";
        }
        else if(n==2)
        {
            cout<<"2 is  a prime number";
        }
        else
        {
            cout<<"number is prime";
        }
    }
}