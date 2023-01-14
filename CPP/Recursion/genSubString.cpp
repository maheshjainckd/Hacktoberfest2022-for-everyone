//Generate all sub strings from a string
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void subseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    char ch=s[0];
    string ros=s.substr(1);
    subseq(ros,ans);
    subseq(ros,ros+ch);
    
    }
int main()
{
    subseq("ABC","");
    cout<<endl;
    return 0;
}