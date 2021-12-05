#include<stdio.h>
#define MAXNODE 20
#define INF_DIS 21

int main()
{
    char graph[MAXNODE][MAXNODE];
    int adjcency;
    int node;
    int startnode,endnode;
    char dist[MAXNODE];
    char queue[191];
    int end,front;
    int testset=1,times;
    int l,l1,l2;

    while(1==scanf("%d",&adjcency))
    {
        for(l=0;l<MAXNODE;l++)
        {
            for(l1=0;l1<MAXNODE;graph[l][l1]=0,l1++);
        }

        for(l=0;l<19;l++)
        {
            for(l1=0;l1<adjcency;l1++)
            {
                scanf("%d",&node);
                node--;
                graph[l][node]=1,graph[node][l]=1;
            }
            if(l<18) scanf("%d",&adjcency);
        }

        scanf("%d",&times);
        printf("Test Set #%d\n",testset);
        for(l=0,end=0,front=0;l<times;end=0,front=0,l++)
        {
            for(l1=0;l1<MAXNODE;dist[l1]=INF_DIS,l1++);

            scanf("%d%d",&startnode,&endnode);

            queue[end]=startnode-1;
            dist[startnode-1]=0;
            for(l1=queue[front],front=0;front<=end;front++,l1=queue[front])
            {
                for(l2=0;l2<MAXNODE;l2++)
                {
                    if(graph[l1][l2] && dist[l2]>dist[l1]+1){
                        dist[l2]=dist[l1]+1;
                        end++;
                        queue[end]=l2;
                    }
                }
            }
            printf("%2d to %2d: %d\n",startnode,endnode,dist[endnode-1]);
        }
        testset++;

        putchar('\n');
    }
    return 0;
}
