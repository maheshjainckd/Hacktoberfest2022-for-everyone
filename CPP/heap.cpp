#include<bits/stdc++.h>
using namespace std;

int main(){
 int p,r;
 cin>>p>>r;
 string q;
 vector<string>w;
 for(int i=0;i<p;i++){
   cin>>q;
   w.push_back(q);
  
 }
unordered_map<string ,vector<string>>u;
 vector<vector<string>>ans;
 for(int i=0;i<p;i++){
   string f=w[i];
   sort(f.begin(),f.end());
   u[f].push_back(w[i]);
  

}

for(int i=0;i<p;i++){
  string f=w[i];
  sort(f.begin(),f.end());
  if(u.find(f) != u.end() and !u.empty()){
     for(int j=0;j<u[f].size();j++){
       cout<<u[f][j]<<" ";
     }
    cout<<"\n";
     while(!u[f].empty()){
       u[f].pop_back();
     }
   }
 }
}