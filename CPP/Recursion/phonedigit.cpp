// Print all posible words from Key pad phone digit
#include<iostream>
using namespace std;

string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void keyPad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;

        return;
    }
    char ch=s[0];
    string code=keypadArr[ch-'0'];
    string ros=s.substr(1);
    for(int i=0;i<code.length();i++){
        keyPad(ros,ans+code[i]);
    }
}
int main()
{
    keyPad("23","");
    cout<<endl;
    return 0;
}