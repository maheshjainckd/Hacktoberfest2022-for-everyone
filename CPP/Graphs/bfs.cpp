#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Graph
{
private:
    unordered_map<int,vector<int>> adjlist;
    vector<bool> visited;
    vector<int> distance;
public:
    void add_edges(int u,int v)
    {
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    void bfs(int src,int n)
    {
        visited.resize(n,false);
        distance.resize(n,0);
        queue<int> q;
        q.push(src);
        distance[src]=0;
        while(q.empty()!=true)
        {
            int temp=q.front();
            q.pop();
            visited[temp]=true;
            for(auto i:adjlist[temp])
            {
                if(visited[i]!=true)
                {
                    q.push(i);
                    distance[i]=distance[temp]+1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<distance[i]<<" ";
        }
    }
};
int main()
{
    int n,e;
    cin>>n;
    cin>>e;
    int u,v;
    Graph obj;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        obj.add_edges(u,v);
    }
    int src;
    cin>>src;
    obj.bfs(src,n);
    return 0;
}