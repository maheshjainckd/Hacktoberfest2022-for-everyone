#include <iostream>
using namespace std;
class test{
    public:
    int a,b;
    test(){
        a=0;
        b=0;
    }
    test(int x, int y)
    {
        a=x;
        b=y;

    }
    test operator +(test t);
    void display();

};
test test:: operator + (test t)
{
    test tes;
    tes.a= a + t.a;
    tes.b= b + t.b;
    return (tes);
}
void test:: display()
{
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;
}

int main()
{
    test t1(10,20);
    test t2(30,40);
    test t3;
    t3=t1+t2;
    t3.display();  
    return 0;
}
