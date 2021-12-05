#include<iostream>
#include<vector>
#define MAXLEN 100001

using namespace std;

vector<int> graph[MAXLEN];
int m;
int cat[MAXLEN];
int color[MAXLEN],pathcat[MAXLEN];

int dfs(int root,int parent)
{
    int l,ans,visited;

    if(cat[root]) pathcat[root]=pathcat[parent]+1;

    if(pathcat[root]>m){
        return 0;
    }

    for(l=0,ans=0,visited=0,color[root]=1;l<graph[root].size();l++)
    {
        if(!color[graph[root][l]]) ans+=dfs(graph[root][l],root),visited++;
    }
    if(visited) return ans;
    else return 1;
}

int main()
{
    int n;
    int l,u,v;

    while(cin>>n>>m)
    {
        pathcat[0]=0;
        for(l=1;l<=n;cin>>cat[l],pathcat[l]=0,color[l]=0,l++);
        for(l=1;l<n;l++)
        {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout<<dfs(1,0)<<'\n';
        for(l=1;l<=n;l++) graph[l].clear();
    }

    return 0;
}
