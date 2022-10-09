//Polymorphism
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//Function overloading

class Ayush{
    public:
    void fun(){
        cout<<"I am a Function with no argument"<<endl;
    }
    void fun(int a){
        cout<<"I am a function with Int argument"<<endl;
    }
    void fun(double a){
        cout<<"I am a function with double argument"<<endl;
    }
};
int main()
{
    Ayush obj;
    obj.fun();
    obj.fun(4);
    obj.fun(6.3);
    
    return 0;
}