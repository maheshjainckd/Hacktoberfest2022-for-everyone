//Encapsulation
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class A{
    public:
    int a;
    void funcA(){
         cout<<"Func a\n";
    }
    private:
    int b;
    void funcB(){
        cout<<"Func B\n";
    }
    protected:
    int c;
    void funcC(){
    cout<<"func C\n";
    }
     
};
int main()
{
    A obj;
    obj.funcA();

    obj.funcB();
    obj.funcC();
    return 0;
}