#define MAXNODE 200
#include <stdio.h>

int main()
{
    int graph[MAXNODE][MAXNODE];
    int queue[MAXNODE];
    int color[MAXNODE];
    int vertexno,edgeno;
    int u,v;
    int l,l1,flag,end,front;

    while(1==scanf("%d",&vertexno))
    {
        if(!vertexno) break;

        scanf("%d",&edgeno);

        end=0,front=0;
        for(l=0;l<vertexno;l++)
        {
            color[l]=0;
            for(l1=0;l1<vertexno;graph[l][l1]=0,l1++);
        }

        for(l=0;l<edgeno;l++)
        {
            scanf("%d%d",&u,&v);
            graph[u][v]=1,graph[v][u]=1;
        }

        queue[front]=0;
        color[front]=0;
        for(l=queue[front],flag=0;;l=queue[front])
        {
            for(l1=0;l1<vertexno;l1++)
            {
               if(graph[l][l1] && !color[l1]){
                    if(color[l]==1) color[l1]=2;
                    else color[l1]=1;
                    end++;
                    queue[end]=l1;
               }
               else if(graph[l][l1] && color[l]==color[l1]){
                    flag=1;
                    break;
               }
            }

            front++;
            if(front==end) break;
        }

        if(flag) puts("NOT BICOLORABLE.");
        else  puts("BICOLORABLE.");
    }

    return 0;
}
