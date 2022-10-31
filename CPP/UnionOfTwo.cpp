/* Given an integer N .
   P is the set of Prime No.s less than N.
   F is the set ofnFibonacci numbers less than N.
   Find the number of elements in the set F union P.*/

#include<iostream>
#include<cmath>
using namespace std;

// Function to find whether a no. is prime or not.
bool isprime(int n)
{
    if(n==1 || n==0)
        return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

//Function to find union of prime no.s and fibonacci numbers till n.
int unionoftwo(int n)
{
    int result=0;
    int a=0,b=1,c=0;
    int arr[n]={0};
    for(int i=0;i<n;i++)
    {
        if(isprime(i))
        {
            arr[i]+=1;
        }
    }
    while(c<n)
    {
        c=a+b;
        arr[c]+=1;
        a=b;
        b=c;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==2)
        {
            result++;
        }
    }
    return result;
}
int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<unionoftwo(n);
}
