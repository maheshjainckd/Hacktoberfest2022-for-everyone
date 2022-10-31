#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> sz;       // by size
    vector<int> parent;
    DSU(int n) {
        sz.resize(n+1 , 0);
        parent.resize(n+1 , 0);
        for(int i=1 ; i<=n ; i++) parent[i] = i;
        for(int i=1 ; i<=n ; i++) sz[i] = 1;
    }
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    bool merge(int u , int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(sz[u] > sz[v]) {
            parent[v] = u;
            sz[u] += sz[v];
        } else {
            parent[u] = v;
            sz[v] += sz[u];
        }
        return true;
    }
    int size(int x) {
        return sz[x];
    }
};

int main() {
    
    DSU d(10);
    d.merge(0 , 8);
    d.merge(8 , 4);

    if(d.find(0) == d.find(8)) {
        cout<<"0 and 8 are connnected"<<endl;
    } else {
        cout<<"0 and 8 are not connnected"<<endl;
    }

    return 0;
}
