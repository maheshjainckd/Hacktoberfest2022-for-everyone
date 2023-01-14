#include<iostream>
#include<stack>

using namespace std;
int main(){
stack<string> s;

s.push("dhar");
s.push("mend");
s.push("solanki");

cout<<""<<s.top()<<endl;
cout<<""<<s.size()<<endl;
s.pop();
cout<<""<<s.size()<<endl;

return 0;
}