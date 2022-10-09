// Swapping two numbers useing XOR without useing any third variable
#include<iostream>
using namespace std;
int main()
{
    int a=4,b=2;
    cout<<a<<" "<<b<<endl;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" " <<b;
    return 0;
}