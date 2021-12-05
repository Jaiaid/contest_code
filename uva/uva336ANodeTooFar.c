#define MAXNODE 30
#include<stdio.h>

struct node{
    unsigned int name;
    int level;
};

int main()
{
    struct node vertices[MAXNODE];
    int graph[MAXNODE][MAXNODE];
    int queue[MAXNODE];
    int NC,TTL,vertexno;
    unsigned int startnode,endnode;
    int caseno=1,l,l1,l2,end,front;

    while(1==scanf("%d",&NC))
    {
        if(!NC) break;

        end=0,front=0;
        for(l=0;l<MAXNODE;vertices[l].name=0,l++)
        {
            for(l1=0;l1<MAXNODE;graph[l][l1]=0,l1++);
        }

        for(l=0;l<NC;l++)
        {
            scanf("%d%d",&startnode,&endnode);
            for(l1=0;l1<=end && vertices[l1].name && vertices[l1].name!=startnode;l1++);
            vertices[l1].name=startnode;
            if(l1>end) end++;

            for(l2=0;l2<=end && vertices[l2].name && vertices[l2].name!=endnode;l2++);
            vertices[l2].name=endnode;
            if(l2>end) end++;

            graph[l1][l2]=1,graph[l2][l1]=1;
        }

        vertexno=end;
        while(1)
        {
            scanf("%d%d",&startnode,&TTL);
            if(!startnode && !TTL) break;

            for(l=0,l1=0;l<MAXNODE;vertices[l].level=-1,l++)
            {
                if(vertices[l].name==startnode) l1=l;
            }

            front=0,end=0;
            queue[front]=l1;
            vertices[l1].level=0;
            for(l=queue[front];front<=end;l=queue[front])
            {
                for(l1=0;l1<=vertexno;l1++)
                {
                    if(graph[l][l1] && vertices[l1].level==-1 && vertices[l].level<TTL){
                        vertices[l1].level=vertices[l].level+1;
                        end++;
                        queue[end]=l1;
                    }
                }

                front++;
            }

            for(l=0,l1=0;l<=vertexno;l++)
            {
                if(vertices[l].level==-1) l1++;
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",caseno,l1,startnode,TTL);
            caseno++;
        }

    }

    return 0;
}
