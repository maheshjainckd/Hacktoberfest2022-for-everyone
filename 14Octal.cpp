// Write a recursive function to print octal of a decimal number.
#include<iostream>
using namespace std;
int Octal(int n, int rem)
{
    static int a;
    if(n>0)                         
    {                               
        Octal(n/8, rem = n%8);      
    }
    else 
    {
        return 1;
    }
    return a = (a * 10) + rem;;
}
int main()
{
    int n, rem=0;
    cout << "Enter a number: ";
    cin >> n;
    n = Octal(n, rem);
    cout << n << endl;
    return 0;
}