#include<stdio.h>
#define MAXNODENUM 100
#define INFINITE 100

int main()
{
    int graph[101][101];
    int case_no=0,path_len_sum;
    int l,l1,l2,u,v,max_node,min_node;

    while(1)
    {
        scanf("%d%d",&u,&v);

        if(u || v){

            max_node=0;
            min_node=MAXNODENUM+1;

            for(l=1;l<=MAXNODENUM;l++)
            {
                for(l1=1;l1<=MAXNODENUM;graph[l][l1]=INFINITE,l1++);
            }

            do
            {
                if(max_node<u) max_node=u;
                if(max_node<v) max_node=v;

                if(min_node>u) min_node=u;
                if(min_node>v) min_node=v;

                graph[u][v]=1;
                scanf("%d%d",&u,&v);

            }while(u || v);

            for(l=min_node;l<=max_node;l++)
            {
                for(l1=min_node;l1<=max_node;l1++)
                {
                    for(l2=min_node;l2<=max_node;l2++)
                    {
                        if(graph[l1][l2]>graph[l1][l]+graph[l][l2]) graph[l1][l2]=graph[l1][l]+graph[l][l2];
                    }
                }
            }
        }
        else break;

        for(l=min_node,path_len_sum=0,l2=-1;l<=max_node;l++)
        {
            for(l1=min_node;l1<=max_node;l1++)
            {
                if(l!=l1 && graph[l][l1]<INFINITE) path_len_sum+=graph[l][l1],l2++;
            }
        }

        printf("Case %d: average length between pages = %.3lf clicks\n",++case_no,path_len_sum/(l2+1.0));
    }
    return 0;
}
