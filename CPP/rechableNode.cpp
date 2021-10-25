//Print all the rechable nodes/vertices in a directed graph from a node/vertex given by the user

#include <iostream>
#include <vector>
using namespace std;

//dfs helper function
void dfsUtil(int source,vector<int> adj[],vector<bool> &visited)
{
    //cout<<"In DFS Util"<<endl;
    visited[source]=true;
    cout<<source<<" ";
    for(int i=0;i<adj[source].size();i++)
    {
        if(!visited[adj[source][i]])
            dfsUtil(adj[source][i],adj,visited);
    }


}

//Using DFS to visit to all the rechable vertices.
void dfs(int s,vector<int> adj[],int V)
{
    vector<bool> visited(V,false);
    dfsUtil(s,adj,visited);
}

//function to add edges
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
}
int main()
{
    //cout << "Hello world!" << endl;
    int V,E;
    cout<<"Enter the Number of vertex: ";
    cin>>V;
    cout<<"Enter the Number of edges: ";
    cin>>E;

    vector<int> adj[V];
    int u,v,start;
    for(int i=0;i<E;i++)
    {
        cout<<"Enter the edge- "<<i+1<<" of directed graph: ";
        cin>>u>>v;
        addEdge(adj,u,v);
        //cout<<endl;
        //cout<<u<<"->"<<adj[u][0]<<endl;
    }

    cout<<"Enter the starting vertex(0 to "<<V-1<<"): "<<endl;
    cin>>start;
    cout<<"Printing reachable vertex from "<<start<<endl;
    dfs(start,adj,V);
    return 0;
}
