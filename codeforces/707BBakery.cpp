#include<iostream>
#include<vector>

#define MAXCITY 100001
#define INF 0xffffffff

class edge{
public:
	unsigned int dest;
	unsigned int len;

	edge(unsigned int dest,unsigned int len){
		this->dest=dest;
		this->len=len;
	}
};

using namespace std;

int main()
{
	int n,m,k;
	vector<edge> graph[MAXCITY];
	unsigned int min_cost;
	
	while(cin>>n>>m>>k)
	{
		unsigned int u,v,len,storage_city;
		for(int l=0;l<m;l++)
		{
			cin>>u>>v>>len;
			graph[u].push_back(edge(v,len));
			graph[v].push_back(edge(u,len));
		}
		
		for(int l=0;l<k;l++)
		{
			cin>>storage_city;
			graph[storage_city].push_back(edge(INF,INF));
		}
		
		min_cost=INF;
		
		if(k==n){
			cout<<"-1"<<endl;
			continue;
		}
		for(int l=1;l<=n;l++)
		{
			if(graph[l].size()>0 && graph[l][graph[l].size()-1].len==INF){
				continue;
			}
			
			for(int l1=0;l1<(int)graph[l].size();l1++)
			{
				int dest=graph[l][l1].dest;
				if(graph[dest].size()>0 && graph[dest][graph[dest].size()-1].len==INF && graph[l][l1].len<min_cost){
					min_cost=graph[l][l1].len;
				}
			}
		}
		
		cout<<(int)min_cost<<endl;

		for(int l=0;l<=n;l++)
		{
			graph[l].clear();
		}
	}
	return 0;
}
