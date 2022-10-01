#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(vector<int> adj[], int V){
    vector<int> res;
    vector<int> vis(V+1, 0);
    for(int i = 1; i<=V; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                res.push_back(node);
                for(auto p:adj[node]){
                    if(!vis[p]){
                        q.push(p);
                        vis[p] = 1;
                    }
                }
            }
        }
    }
    return res;
}

void dfs(vector<int> adj[], vector<int>& res, int node, vector<int> &vis){
    res.push_back(node);
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]) dfs(adj, res, i, vis);
    }
    return;
}

vector<int> dfsorder(vector<int> adj[], int V){
    vector<int> res;
    vector<int> vis(V+1, 0);
    for(int i=1; i<=V; i++){
        if(!vis[i]) dfs(adj, res, i, vis);
    }
    return res;
}

bool checkCycle_usingBFS(vector<int> adj[], int V){
    vector<int> vis(V+1, 0);

    for(int i = 1; i<=V; i++){
        if(!vis[i]){
            queue<pair<int, int>> q;
            q.push({i, -1});
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front().first;
                int par = q.front().second;
                q.pop();
                for(auto p : adj[node]){
                    if(!vis[p]) {
                        q.push({p, node});
                        vis[p] = 1;
                    }
                    else{
                        if(par != p) return true;
                    }
                }
            }
        }
    }
    return false;
}

bool checkCycle_usingdfs(vector<int> adj[], vector<int>& vis, int par, int node){
    vis[node] = 1;
    for(auto p : adj[node]){
        if(!vis[p]) {
            if(checkCycle_usingdfs(adj, vis, node, p)) return true;
        }
        else{
            if(par != p) return true;
        }
    }
    return false;
}

int lengthofcycle = -1;

void count_length(vector<int> adj[], int par, int node, vector<int>& vis){
    vis[node] = vis[par] + 1;
    for(int p : adj[node]){
        if(vis[p] == -1){
            count_length(adj, node, p, vis);
        }
        else{
            if(par != p){
                if(lengthofcycle < vis[node]-vis[p]+1) lengthofcycle=vis[node]-vis[p]+1;
            }
        }
    }
    return;
}

int length_of_longest_cycle_using_DFS(vector<int> adj[], int V){
    vector<int> vis(V+1, -1);
    for(int i = 1; i<=V; i++){
        if(vis[i] == -1){
            count_length(adj, 0, i, vis);
        }
    }
    return lengthofcycle;
}

bool checkCycle(vector<int> adj[], int V){
    vector<int> vis(V+1, 0);
    for(int i = 1; i<=V; i++){
        if(!vis[i]){
            if(checkCycle_usingdfs(adj, vis, 0, i)) return true;
        }
    }
    return false;
}

bool checkBipartiteBFS(vector<int> adj[], vector<int>& vis, int par, int node){
    queue<int> q;
    q.push(node);
    vis[node] = (vis[par]+1)%2;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(int i : adj[n]){
            if(vis[i] == -1){
                q.push(i);
                vis[i] = (vis[n]+1)%2;
            }
            else{
                if(vis[i] == vis[n]) return false;
            }
        }
    }
    return true;
}

bool isBipartite_usingBFS(vector<int> adj[], int V){
    vector<int> vis(V+1, -1);
    vis[0] = 0;
    for(int i = 1; i<=V; i++){
        if(vis[i] == -1){
            if(!checkBipartiteBFS(adj, vis, 0, i)) return false;
        }
    }
    return true;
}

bool checkBipartiteDFS(vector<int> adj[], vector<int>& vis, int par, int node){
    vis[node] = (vis[par]+1)%2;
    for(int i : adj[node]){
        if(vis[i] == -1) {
            if(!checkBipartiteDFS(adj, vis, node, i)) return false;
        }
        else{
            if(vis[i] == vis[node]) return false;
        }
    }
    return true;
}

bool isBipartite_usingDFS(vector<int> adj[], int V){
    vector<int> vis(V+1, -1);
    vis[0] = 0;
    for(int i = 1; i<=V; i++){
        if(vis[i] == -1){
            if(!checkBipartiteDFS(adj, vis, 0, i)) return false;
        }
    }
    return true;
}

bool check_cycle_dir(vector<int> adj[], vector<int> vis, vector<int> dfsvis, int node){
    vis[node] = 1;
    // if(dfsvis[node]) return true;
    dfsvis[node] = 1;
    for(int i : adj[node]){
        if(!vis[i]){
            if(check_cycle_dir(adj, vis, dfsvis, i)) return true;
        }
        else if(dfsvis[node]) return true;
    }
    dfsvis[node] = 0;
    return false;

}

bool cyclein_directed(vector<int> adj[], int V){
    vector<int> vis(V+1, 0);
    vector<int> dfsvis(V+1, 0);
    for(int i = 1; i<=V; i++){
        if(!vis[i]){
            if(check_cycle_dir(adj, vis, dfsvis, i)) return true;
        }
    }
    return false;
}

void topodfs(vector<int> adj[], stack<int>& s, int node, vector<int> &vis){
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]) topodfs(adj, s, i, vis);
    }
    s.push(node);
    return;
}

vector<int> topoSort_usingDFS(vector<int> adj[], int V){
    vector<int> vis(V+1, 0);
    vector<int> res;
    stack<int> s;
    for(int i = 1; i<=V; i++){
        if(!vis[i]){
            topodfs(adj, s, i, vis);
        }
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

vector<int> kahnalgo(vector<int> adj[], int V){
    // TopoSort using BFS
    vector<int> res;
    vector<int> indeg(V, 0);
    for(int i = 0; i<V; i++){
        for(int p : adj[i]){
            indeg[p]++;
        }
    }
    queue<int> q;

    for(int i = 0; i<V; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        res.push_back(node);
        q.pop();
        for(int p : adj[node]){
            indeg[p]--;
            if(indeg[p] == 0) q.push(p);
        }
    }
    return res;
}

bool detectcycle_kahnalgo(vector<int> adj[], int V){
    // TopoSort using BFS
    // vector<int> res;
    int cnt = 0;
    vector<int> indeg(V, 0);
    for(int i = 0; i<V; i++){
        for(int p : adj[i]){
            indeg[p]++;
        }
    }
    queue<int> q;

    for(int i = 0; i<V; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        // res.push_back(node);
        cnt++;
        q.pop();
        for(int p : adj[node]){
            indeg[p]--;
            if(indeg[p] == 0) q.push(p);
        }
    }
    cout<<cnt<<endl;
    if(cnt==V) return false;
    else return true;
}

vector<int> shortestpath_undir(vector<int> adj[], int V, int src){
    queue<int> q;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    q.push(src);
    // for(int i = 0; i<V; i++){
        // if(dist[i] == INT_MAX){
            // q.push(i);
            // dist[i] = 
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int p : adj[node]){
            if(dist[p] > dist[node]+1){
                q.push(p);
                dist[p] = dist[node]+1;
            }
            // else{
                // dist[p] = min(dist[node]+1, dist[p]);
            // }
        }
    }
    return dist;
}

void topo_dfs(vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& s, int node){
    vis[node] = 1;
    for(auto p : adj[node]){
        // cout<<p.first<<endl;
        if(!vis[p.first]) topo_dfs(adj, vis, s, p.first);
    }
    s.push(node);
    return;
}

vector<int> shortestdist_DAG(int src, vector<pair<int,int>> adj[], int N){
    stack<int> s;
    vector<int> vis(N, 0);
    
    for(int i = 0; i<N; i++){
        if(!vis[i]) topo_dfs(adj, vis, s, i);
    }
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;   //source distance is 0
    // cout<<s.size()<<endl;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        // cout<<dist[node]<<endl;
        if(dist[node] != INT_MAX){
            for(auto t : adj[node]){
                if(dist[t.first] > dist[node]+t.second){
                    dist[t.first] = dist[node] + t.second;
                }
            }
        }
    }
    // cout<<dist.size()<<endl;
    // for(int i = 0; i<dist.size(); i++){
    //     if(dist[i]!=INT_MAX)cout<<dist[i]<<"   ";
    //     else cout<<"INFINITY"<<"  ";
    // }
    return dist;
}

vector<int> dijkstra_algo(int src, vector<pair<int, int>> adj[], int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int> dist(V+1, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        int dt = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for(auto it : adj[prev]){
            int next = it.first;
            int ndist = it.second;
            if(dist[next]>dist[prev]+ndist){
                dist[next] = dist[prev]+ndist;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

void MST_usingPrimsAlgo(vector<pair<int, int>> adj[], int N){
    int key[N];
    bool MST[N];
    int parent[N];
    for(int i = 0; i<N; i++){
        key[i] = INT_MAX;
        MST[i] = false;
        parent[i] = -1;
    }
    
    key[0] = 0;
    
    //Brute Force
    // for(int cnt = 0; cnt <N-1; cnt++){
    //     int mnm = INT_MAX;
    //     int u;
    //     for(int v = 0; v<N; v++){
    //         if(MST[v]==true) continue;
    //         if(mnm<key[v]){
    //             mnm = key[v];
    //             u = v;
    //         }
    //     }
    //     MST[u] = true;
    //     for(auto it : adj[u]){
    //         int v = it.first;
    //         int wt = it.second;
    //         if(!MST[v] && key[v]>wt){
    //             key[v] = wt;
    //             parent[v] = u;
    //         }
    //     }
    // }
    

    // efficient approach
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, 0});
    for(int cnt = 0; cnt<N-1; cnt++){
        int u = pq.top().second;
        pq.pop();
        MST[u] = true;
        for(auto it : adj[u]){
            int v = it.first;
            int wt = it.second;
            if(!MST[v] && wt<key[v]){
                key[v] = wt;
                parent[v] = u;
                pq.push({wt, v});
            }
        }
    }
    for(int i = 1; i<N; i++){
        cout<<parent[i]<<"  "<<i<<"  "<<endl;
    }
}

int main(){
    int n, m;    // n - number of nodes          m - no. of connections(edges)  
    cin>>n>>m;
    // vector<int> adj[n+1];
    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i<m; i++){
        int u,v;
        int val;
        cin>>u>>v>>val;
        
        adj[u].push_back({v, val});
        adj[v].push_back({u, val});
    }
    // vector<int> res = dijkstra_algo(1, adj, n);
    // cout<<res.size()<<endl;
    // for(int i = 0; i<res.size(); i++){
    //     if(res[i]!=INT_MAX) cout<<res[i]<<"   ";
    //     else cout<<"INFINITY"<<"  ";
    // }
    MST_usingPrimsAlgo(adj, n);

    // bool r = detectcycle_kahnalgo(adj, n);
    // cout<<r<<endl;
    // int g = length_of_longest_cycle_using_DFS(adj, n);
    // cout<<g<<endl;
    // bool t = cyclein_directed(adj, n);
    // cout<<t<<endl;
    // cout<<endl;
    return 0;
}
