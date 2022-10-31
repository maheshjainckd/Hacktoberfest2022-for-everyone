#include <bits/stdc++.h>
using namespace std;
unordered_map <string,bool> mp;

bool solve(string a ,string b){
    if(a.length()!=b.length()){
        return false;
    }
    if(a.compare(b)==0){
        return true;
    }
    if(a.length()<=1){
        return false;
    }
    int n= a.length();
    bool flag =false;

    string key= (a+" "+b);
    if(mp.find(key)!=mp.end()){
        return mp[key];
    }

    for(int i=1;i<=n-1;i++){
        //gr eat   eat gr
        if(solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)))
        {flag = true;
        break;}

        //gr eat   gr ate 
        else if(solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)))
        {flag= true;
        break;}
    }

    return mp[key]=flag;

}


int main(){
    string a,b;
    cin>>a;
    cin>>b;
    string x=a;
    string y=b;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(x!=y){
        cout<<"false";
    }
    else{
         if(solve(a,b)){
        cout<<"true";
    }
    else
    cout<<"false";
    }

    
   
    


}