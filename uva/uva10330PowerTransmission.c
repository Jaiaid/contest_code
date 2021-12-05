#include<stdio.h>
#define MAXNODENUM 202
#define MAXREGENUM 101
#define INFINITE -1

unsigned int network_capacity[MAXNODENUM][MAXNODENUM];
int node_color[MAXNODENUM];
int node_parent[MAXNODENUM];
unsigned int node_capacity[MAXREGENUM];
int queue[MAXNODENUM];

int bfs(int n)
{
    int l,l1,front=0,end=0,min_flow=INFINITE;
    for(l=0;l<=n;node_color[l]=0,node_parent[l]=l,l++);

    queue[front]=0;
    node_color[l]=1;
    while(front<=end)
    {
        l=queue[front++];

        if(l==n) break;

        for(l1=0;l1<=n;l1++)
        {
            if(network_capacity[l][l1] && !node_color[l1]){
                node_parent[l1]=l;
                node_color[l1]=1;
                queue[++end]=l1;
            }
        }
        node_color[l]=2;
    }

    l=n;
    while(l!=node_parent[l])
    {
        if(min_flow>network_capacity[node_parent[l]][l]) min_flow=network_capacity[node_parent[l]][l];
        l=node_parent[l];
    }

    if(l!=0) min_flow=0;

    return min_flow;
}

int main()
{
    int N,M,B,D;
    int l,l1,l2,i,j,C,tmp,min_flow;
    int total_flow;

    while(1==scanf("%d",&N))
    {
        for(l=0,tmp=N+N+1;l<=tmp;l++)
        {
            for(l1=0,tmp=N+N+1;l1<=tmp;l1++) network_capacity[l][l1]=0;
        }

        for(l=1;l<=N;l++) scanf("%d",&node_capacity[l]);

        scanf("%d",&M);
        for(l=0;l<M;l++)
        {
            scanf("%d%d%d",&i,&j,&C);
            tmp=i+N;
            network_capacity[tmp][j]+=C;
            network_capacity[i][tmp]=node_capacity[i];

        }

        scanf("%d%d",&B,&D);
        for(l=0;l<B;l++)
        {
            scanf("%d",&i);
            network_capacity[0][i]=node_capacity[i];
        }
        for(l=0,tmp=N+N+1;l<D;l++)
        {
            scanf("%d",&i);
            network_capacity[i+N][tmp]=node_capacity[i];
            network_capacity[i][i+N]=node_capacity[i];
        }

        N+=N+1;

        total_flow=0;
        while(min_flow=bfs(N))
        {
            l=N;
            while(l)
            {
                network_capacity[node_parent[l]][l]-=min_flow;
                network_capacity[l][node_parent[l]]+=min_flow;
                l=node_parent[l];
            }
            total_flow+=min_flow;
        }

        printf("%d\n",total_flow);
    }
    return 0;
}
