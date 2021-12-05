#include <iostream>
#include<algorithm>
#define MAXPOS 10001
#define MAXROAD 1000000

using namespace std;

struct edge{
    int cost;
    int u,v;
    bool operator<(const edge& q)const;
};

struct component{
    int parent;
    int rank;
};

bool edge::operator<(const edge& q)const
{
    return cost<q.cost;
}

component place[MAXPOS];

int find_parent(int u)
{
    return (place[u].parent==u)?u:find_parent(place[u].parent);
}

void component_union(int u,int v)
{
    u=find_parent(u),v=find_parent(v);
    if(place[u].rank<place[v].rank) place[u].parent=v;
    else{
        place[v].parent=u;
        if(place[u].rank==place[v].rank) place[u].rank++;
    }
}

int main()
{
    edge *road;
    road = new edge[MAXROAD];
    int tc,N,M,Acost;
    int l,l1,caseno = 0,tmp_total_cost;
    int total_cost,num_of_airport;

    cin>>tc;
    while (caseno<tc)
    {
        cin>>N>>M>>Acost;

        for(l=0;l<M;l++) cin>>road[l].u>>road[l].v>>road[l].cost;

        for(l=1;l<=N;place[l].parent=l,place[l].rank=0,l++);

        sort(road,road+M);

        for(l=0,l1=0,tmp_total_cost=0,num_of_airport=N,total_cost=Acost*N;l<M;l++)
        {
            if(find_parent(road[l].u)!=find_parent(road[l].v)){
                component_union(road[l].u,road[l].v);
                tmp_total_cost+=road[l].cost;
                l1++;
                if(tmp_total_cost+Acost*(N-l1)<total_cost){
                    total_cost=tmp_total_cost+Acost*(N-l1);
                    num_of_airport=N-l1;
                }
            }
        }

        cout<<"Case #"<<++caseno<<": "<<total_cost<<' '<<num_of_airport<<'\n';
    }
    return 0;
}
