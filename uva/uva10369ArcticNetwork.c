#include<stdio.h>
#include<math.h>

#define MAXARALEN 124750
#define MAXNODENUM 500


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

void Quick_sort(struct edge *ara,int ini_indx,int fin_indx);
void component_union(int indx1,int indx2);
int find_parent(int indx1);

struct edge path[MAXARALEN];
struct node outpost[MAXNODENUM];
struct component forest[MAXNODENUM];

int main()
{
    int tc;
    int S,P;
    int maxedgenum;
    int l,l1;

    scanf("%d",&tc);

    while(tc)
    {
        scanf("%d%d",&S,&P);

        for(l=0;l<P;l++)
        {
            forest[l].parent=l;
            forest[l].rank=0;
            scanf("%d%d",&outpost[l].x,&outpost[l].y);
            outpost[l].name=l;
        }

        for(l=0,maxedgenum=0;l<P;l++)
        {
            for(l1=l+1;l1<P;l1++)
            {
                path[maxedgenum].len=sqrt((outpost[l].x-outpost[l1].x)*(outpost[l].x-outpost[l1].x)+(outpost[l].y-outpost[l1].y)*(outpost[l].y-outpost[l1].y));
                path[maxedgenum].u=l,path[maxedgenum].v=l1;
                maxedgenum++;
            }
        }

        Quick_sort(path,0,maxedgenum-1);

        for(l=0,l1=0,P-=S;l1<P;l++)
        {
            if(find_parent(path[l].u)!=find_parent(path[l].v)){
                component_union(path[l].u,path[l].v);
                l1++;
            }
        }

        printf("%.2lf\n",path[l-1].len);
        tc--;
    }
    return 0;
}

void Quick_sort(struct edge *ara,int ini_indx,int fin_indx)
{
    if(ini_indx>fin_indx) return;
    int l1=ini_indx-1,l;
    struct edge tmp;

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
