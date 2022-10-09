//Reverse a string useing recursion
#include<iostream>
using namespace std;
void revese(string s){

    if(s.length()==0){      //base case
        return;
    }
    string ros=s.substr(1);
    revese(ros);
    cout<<s[0];
}
int main()
{
    revese("binod");
    return 0;
}