#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
int main()
{
int n,m;//vertex,edge
cin>>n>>m;
	vector<int>dis(n+1,inf);
	vector<vector<pair<int,int>>>graph(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
	cin>>u>>v>>w;
	graph[u].push_back({v,w});
	graph[v].push_back({u,w});
	}
	int source;
	cin>>source;
	dis[source]=0;
	set<pair<int,int>>s;
	s.insert({0,source});///wt , vertex
	while(!s.empty())
	{
		auto x=*(s.begin());//points to first element
		s.erase(x);
		for(auto it:graph[x.second])//neighbours
		{ //it.first is the  vertex
			if(dis[it.first]>dis[x.second]+it.second)//dis of neighbours
			{
				s.erase({dis[it.first],it.first});
				dis[it.first]=dis[x.second]+it.second;
				s.insert({dis[it.first],it.first});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]<inf)
		cout<<dis[i]<<" ";
		else cout<<-1;
	}
}
