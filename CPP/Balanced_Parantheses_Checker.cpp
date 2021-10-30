#include <bits/stdc++.h>
 using namespace std;

 int main(){
     int n;
     cout<<"Enter the number of parantheses";
     cin>>n;

     cout<<"Enter the parantheses"<<endl;
     string in;
     cin>>in;
     stack <char> s;
     int flag=0;
     for(int i=0; i<in.size(); i++){
         if(in[i]=='('){
             s.push('(');
         }
         else{
             if(s.empty()||s.top()==')'){
                 cout<<"Invalid";
                 flag=1;
                 break;
             }
             else if (s.top()=='('){
                 s.pop();
             }
         }
     }

     if(s.empty() && flag==0){
         cout<<"valid";
     }
     else if(!s.empty() && flag==0){
         cout<<"invalid";    

     }


 } 
