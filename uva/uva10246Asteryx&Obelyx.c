#include<stdio.h>
#define INF (~0)
#define MAXNODE 81


int main()
{
    unsigned int cost[MAXNODE][MAXNODE],fcost[MAXNODE][MAXNODE],C,R,Q;
    unsigned int tc=1,l,l1,l2,tmpfcost,u,v;
    unsigned int ans;

    freopen("E:\\input.txt","r",stdin);
    freopen("E:\\output.txt","w",stdout);

    while(3==scanf("%u%u%u",&C,&R,&Q))
    {
        if(C || R || Q){
            if(tc>1) putchar('\n');

            for(l=1;l<=C;l++)
            {
                for(l1=1;l1<=C;l1++) cost[l][l1]=INF,fcost[l][l1]=0;
            }

            for(l=1;l<=C;scanf("%u",&fcost[l][l]),l++);

            for(l=1;l<=R;l++)
            {
                scanf("%u%u%u",&u,&v,&l1);
                cost[u][v]=l1;
                cost[v][u]=l1;
                fcost[u][v]=(fcost[u][u]>fcost[v][v])?fcost[u][u]:fcost[v][v];
                fcost[v][u]=fcost[u][v];
            }

            for(l=1;l<=C;l++)
            {
                for(l1=1;l1<=C;l1++)
                {
                    for(l2=1;l2<=C;l2++)
                    {
                        if(cost[l1][l]<INF && cost[l][l2]<INF){
                            tmpfcost=(fcost[l1][l]>fcost[l][l2])?fcost[l1][l]:fcost[l][l2];

                            if(cost[l1][l]+cost[l][l2]+tmpfcost<cost[l1][l2]+fcost[l1][l2]){
                                cost[l1][l2]=cost[l1][l]+cost[l][l2];
                                fcost[l1][l2]=tmpfcost;
                            }
                        }
                    }
                }
            }

            for(l=1;l<=C;l++)
            {
                for(l1=1;l1<=C;l1++)
                {
                    for(l2=1;l2<=C;l2++)
                    {
                        if(cost[l1][l]<INF && cost[l][l2]<INF){
                            tmpfcost=(fcost[l1][l]>fcost[l][l2])?fcost[l1][l]:fcost[l][l2];

                            if(cost[l1][l]+cost[l][l2]+tmpfcost<cost[l1][l2]+fcost[l1][l2]){
                                cost[l1][l2]=cost[l1][l]+cost[l][l2];
                                fcost[l1][l2]=tmpfcost;
                            }
                        }
                    }
                }
            }

            printf("Case #%u\n",tc++);
            for(l=0;l<Q;l++)
            {
                scanf("%d%d",&u,&v);
                ans=cost[u][v];
                if(ans!=INF){
                    ans+=fcost[u][v];
                    printf("%u\n",ans);
                }
                else puts("-1");
            }
        }
        else break;
    }
    return 0;
}

