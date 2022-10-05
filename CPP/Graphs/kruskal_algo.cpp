#include<bits/stdc++.h>
using namespace std;
int s[8] ={-1,-1,-1,-1,-1,-1,-1,-1};
void set_union(int u,int v){
    if(s[u]<s[v]){
        s[u]+=s[v];
        s[v] = u;
    }
    else{
        s[v]+=s[u];
        s[u] = v;
    }
}
int set_find(int u){
    int x = u;
    while(s[x]>0){
        x = s[x];
    }
    return x;
}
int main(){
    int edges[3][9] = {
        {1,1,2,2,3,4,4,5,5},
        {2,6,3,7,4,5,7,6,7},
        {25,5,12,10,8,16,14,20,18}
    };
    int included[9] = {0};
    int t[2][6];
    int minm=INT_MAX,u,v,idx;
    for(int i=0; i<9; i++){
        if(minm>edges[2][i]){
            minm = edges[2][i];
            u = edges[0][i];
            v = edges[1][i];
            idx = i;
        }
    }
    included[idx] = 1;
    t[0][0] = u;
    t[1][0] = v;
    for(int i=1; i<6; ){
        minm = INT_MAX;
        for(int j=0; j<9; j++){
            if(included[j]!=1 and minm>edges[2][j]){
                minm = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                idx = j;
            }
        }
        int u_parent = set_find(u);
        int v_parent = set_find(v);
        
        if(u_parent != v_parent){
            set_union(u_parent,v_parent);
            t[0][i] = u;
            t[1][i] = v;
            i++;
        }
        included[idx] = 1;
    }
    for(int i=0; i<6; i++){
        cout<<t[0][i]<<"->"<<t[1][i]<<endl;
    }
    return 0;
}