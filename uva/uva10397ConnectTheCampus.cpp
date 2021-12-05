#include<iostream>
#include<cmath>

#define MAXARALEN 280875
#define MAXNODENUM 750

using namespace std;

struct node{
    int x;
    int y;
    int name;
};

struct edge{
    double len;
    int u;
    int v;
};

struct component{
    int parent;
    int rank;
};

void Quick_sort(edge *ara,int ini_indx,int fin_indx);
void component_union(int indx1,int indx2);
int find_parent(int indx1);

edge cable[MAXARALEN];
node building[MAXNODENUM];
component forest[MAXNODENUM];
double graph[MAXNODENUM][MAXNODENUM];

int main()
{
    int N,M;
    int maxedgenum;
    int l,l1;
    int indx1,indx2;
    double sum;
    cout.precision(2);
    cout.setf(ios::fixed);

    while(cin>>N)
    {
        for(l=0;l<N;l++)
        {
            forest[l].parent=l;
            forest[l].rank=0;
            for(l1=0;l1<N;graph[l][l1]=0,l1++);
            cin>>building[l].x>>building[l].y;
            building[l].name=l;
        }

        for(l=0,maxedgenum=0;l<N;l++)
        {
            for(l1=l+1;l1<N;l1++)
            {
                cable[maxedgenum].len=sqrt((building[l].x-building[l1].x)*(building[l].x-building[l1].x)+(building[l].y-building[l1].y)*(building[l].y-building[l1].y));
                cable[maxedgenum].u=l,cable[maxedgenum].v=l1;
                maxedgenum++;
            }
        }

        Quick_sort(cable,0,maxedgenum-1);

        cin>>M;
        for(l=0;l<M;l++)
        {
            cin>>indx1>>indx2;
            indx1--,indx2--;
            component_union(indx1,indx2);
            graph[indx1][indx2]=1;
            graph[indx2][indx1]=1;
        }


        for(l=0,sum=0;l<maxedgenum;l++)
        {
            if(graph[cable[l].u][cable[l].v]==0){
                if(find_parent(cable[l].u)!=find_parent(cable[l].v)){
                    sum+=cable[l].len;
                    component_union(cable[l].u,cable[l].v);
                    graph[cable[l].u][cable[l].v]=1;
                    graph[cable[l].v][cable[l].u]=1;
                }
            }
        }

        cout<<sum<<'\n';
    }
    return 0;
}

void Quick_sort(edge *ara,int ini_indx,int fin_indx)
{
    if(ini_indx>fin_indx) return;
    int l1=ini_indx-1,l;
    edge tmp;

    for(l=ini_indx;l<fin_indx;l++)
    {
        if(ara[l].len<ara[fin_indx].len){
            l1++;
            tmp=ara[l];
            ara[l]=ara[l1];
            ara[l1]=tmp;
        }
    }
    l1++;
    tmp=ara[l];
    ara[l]=ara[l1];
    ara[l1]=tmp;

    Quick_sort(ara,ini_indx,l1-1);
    Quick_sort(ara,l1+1,fin_indx);

}

void component_union(int indx1,int indx2)
{
    indx1=find_parent(indx1),indx2=find_parent(indx2);
    if(forest[indx1].rank<forest[indx2].rank) forest[indx1].parent=indx2;
    else{
        forest[indx2].parent=indx1;
        if(forest[indx1].rank==forest[indx2].rank) forest[indx1].rank++;
    }
}

int find_parent(int indx1)
{
    if(forest[indx1].parent!=indx1){
        indx1=find_parent(forest[indx1].parent);
    }
    return indx1;
}
