#include<stdio.h>
#define MAXNODE 22
#define INF 462001

int main()
{
    char name[22][11];
    int cost[MAXNODE][MAXNODE],N,M;
    int l,l1,l2,u,v,k,ans;
    int tc=1;

    while(1==scanf("%d",&N))
    {
        if(!N) break;

        scanf("%d",&M);

        for(l=0;l<N;l++)
        {
            for(l1=0;l1<N;cost[l][l1]=INF,l1++);
            cost[l][l]=0;                        //this is done to keep the sum result unaffected by cost[l][l]
            scanf("%s",name[l]);
        }

        for(l=0;l<M;l++)
        {
            scanf("%d%d%d",&u,&v,&k);
            u--,v--;
            cost[u][v]=k;
            cost[v][u]=k;
        }

        for(l=0;l<N;l++)
        {
            for(l1=0;l1<N;l1++)
            {
                for(l2=0;l2<N;l2++)
                {
                    if(cost[l1][l2]>cost[l1][l]+cost[l][l2]){
                        cost[l1][l2]=cost[l1][l]+cost[l][l2];
                    }
                }
            }
        }

        for(l=0,u=INF;l<N;l++)
        {
            for(l1=0,k=0;l1<N;k+=cost[l][l1],l1++);

            if(u>k) u=k,ans=l;
        }

        printf("Case #%d : %s\n",tc++,name[ans]);
    }
    return 0;
}

