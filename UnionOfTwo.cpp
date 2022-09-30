#include<iostream>
#include<cmath>
using namespace std;
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
  cout<<"Enter the size of array"<<endl;
    cin>>n;
    cout<<unionoftwo(n);
}
