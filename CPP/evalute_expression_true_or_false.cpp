#include <bits/stdc++.h>
using namespace std;
unordered_map <string,int> mp;
int solve(string s,int i,int j,bool isTrue){
    int ans=0;
    if(i==j){
        if(isTrue==1){
            return s[i]=='T';}
        else
       return s[i]=='F';
    }
    if(i>j){return false;}

    string temp= to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }

    for(int k=i+1;k<=j-1;k=k+2){
        int LT= solve(s,i,k-1,1);
        int RF= solve(s,k+1,j,0);
        int LF= solve(s,i,k-1,0);
        int RT= solve(s,k+1,j,1);

        if(s[k]=='|'){
            if(isTrue==1){
                ans=ans + LT*RF + RT*LF + LT*RT;
            }
            else
            ans=ans+LF*RF;
        }
        else if(s[k]=='&'){
            if(isTrue==1){
                ans= ans + LT*RT;
            }
            else  
            ans = ans + LT*RF + LF*RT + LF*RF;
        }
        else if(s[k]=='^'){
            if(isTrue==1){
                ans = ans + LT*RF + LF*RT;
            }
            else
            ans = ans +LT*RT + LF*RF;
        }
    }
    return mp[temp]=ans;


}
int main(){
    mp.clear();
    string s;
    cin>>s;
    int n =s.length();
    cout<<solve(s,0,n-1,1);
}