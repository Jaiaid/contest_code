#include<stdio.h>
#include<stdlib.h>
#define MAXNODENUM 1001
#define INFINITE -1

unsigned int graph[MAXNODENUM][MAXNODENUM],next[MAXNODENUM][MAXNODENUM],tax[MAXNODENUM];

void print_path(int u,int v)
{
    printf("%d-->",u);
    u=next[u][v];

    while(u!=v)
    {
        printf("%d-->",u);
        u=next[u][v];
    }
    printf("%d",u);
}

int main()
{

    char inputstr[20];
    int M,tc=0,N;
    int l,l1,l2,u,v,flag=0;

    scanf("%d",&M);
    while(M)
    {
        scanf("%u",&graph[1][1]);
        if(graph[1][1]!=INFINITE) next[1][1]=1;

        for(N=1;'\n'!=getchar();)
        {
            N++;
            scanf("%u",&graph[1][N]);
            if(graph[1][N]!=INFINITE) next[1][N]=N;
        }
        for(l=2;l<=N;l++)
        {
            for(l1=1;l1<=N;l1++)
            {
                scanf("%u",&graph[l][l1]);
                if(graph[l][l1]!=INFINITE) next[l][l1]=l1;
            }
        }

        for(l=1;l<=N;l++) scanf("%u",&tax[l]);
        getchar();

        for(l=1;l<=N;l++)
        {
            for(l1=1;l1<=N;l1++)
            {
                for(l2=1;l2<=N;l2++)
                {
                    if(graph[l1][l]!=INFINITE && graph[l][l2]!=INFINITE){
                        if(graph[l1][l2]>graph[l1][l]+graph[l][l2]+tax[l]){
                            graph[l1][l2]=graph[l1][l]+graph[l][l2]+tax[l];
                            next[l1][l2]=next[l1][l];
                        }
                    }
                }
            }
        }

        while(NULL!=gets(inputstr))
        {
            if(!inputstr[0]) break;

            if(flag) putchar('\n');
            for(l=0;inputstr[l]!=' ';l++);
            u=atoi(inputstr);
            v=atoi(inputstr+l);

            printf("From %d to %d :\nPath: ",u,v);
            print_path(u,v);
            printf("\nTotal cost : %u\n",graph[u][v]);
            flag++;
        }

        M--;
    }
    return 0;
}
