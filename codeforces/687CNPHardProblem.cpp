#define UNOCCUPIED 0
#define GRAPH1 1
#define GRAPH2 2

#include<iostream>
#include<vector>

using namespace std;

vector< vector<int> > adjlist;
vector<int> graph1,graph2;
vector<int> color;

int dfs(int init_node)
{
	if(color[init_node]==GRAPH1){
		graph1.push_back(init_node);
	}
	else{
		graph2.push_back(init_node);
	}
	
	for(int l=0;l<(int)adjlist[init_node].size();l++)
	{
		if(color[adjlist[init_node][l]]==UNOCCUPIED){
			if(color[init_node]==GRAPH1){
				color[adjlist[init_node][l]]=GRAPH2;
			}
			else{
				color[adjlist[init_node][l]]=GRAPH1;
			}
			
			if(dfs(adjlist[init_node][l])==-1){
				return -1;
			}
		}
		else if(color[adjlist[init_node][l]]==color[init_node]){
			return -1;
		}
	}
	
	return 0;
}

int main()
{
	int n,m;
	int tmp,tmp1;
	int ans;
	
	while(cin>>n>>m)
	{
		adjlist.clear();
		graph1.clear();
		graph2.clear();
		color.clear();
		
		for(int l=0;l<=n;l++)
		{
			vector<int> tmp;
			adjlist.push_back(tmp);
			color.push_back(UNOCCUPIED);
		}
		for(int l=0;l<m;l++)
		{	
			cin>>tmp>>tmp1;
			adjlist[tmp].push_back(tmp1);
			adjlist[tmp1].push_back(tmp);
		}

		color[tmp]=GRAPH1;
	
		while(true)
		{
			int l;
			ans=dfs(tmp);
			
			if(ans==-1){
				break;
			}
			else{
				for(l=1;l<=n && (color[l]!=UNOCCUPIED || adjlist[l].size()==0);l++);
			}
			
			if(l>n){
				break;
			}
			else{
				color[l]=GRAPH1;
				tmp=l;
			}
		}
		
		if(ans!=-1){
			cout<<graph1.size()<<endl;
			for(int l=0;l<(int)graph1.size();l++) cout<<graph1[l]<<' ';
			cout<<endl;
			
			cout<<graph2.size()<<endl;
			for(int l=0;l<(int)graph2.size();l++) cout<<graph2[l]<<' ';
			cout<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
