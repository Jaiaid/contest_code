#include<stdio.h>

int main()
{
    int arax[100000],aray[100000],hotlx[100000],hotly[100000];
    int N,M,C,H,ansindx;
    double sumx,sumy;
    while(2==scanf("%d%d",&N,&M))
    {
        int l,tmp1,dist;
        scanf("%d",&C);

        for(l=0,sumx=0,sumy=0;l<C;l++)
        {
            scanf("%d%d",arax+l,aray+l);
            sumx+=arax[l],sumy+=aray[l];
        }

        sumx/=C,sumy/=C;

        scanf("%d",&H);

        for(l=0,ansindx=0,dist=N+M;l<H;l++)
        {
            scanf("%d%d",hotlx+l,hotly+l);

            if(hotlx[l]-sumx>0) tmp1=hotlx[l]-sumx;
            else tmp1=sumx-hotlx[l];

            if(hotly[l]-sumy>0) tmp1+=hotly[l]-sumy;
            else tmp1+=sumy-hotly[l];

            if(dist>=tmp1){
                dist=tmp1;
                ansindx=l;
            }
        }

        for(l=0,dist=0;l<C;l++)
        {
            if(hotlx[ansindx]-arax[l]>0) tmp1=hotlx[ansindx]-arax[l];
            else tmp1=arax[l]-hotlx[ansindx];

            if(hotly[ansindx]-aray[l]>0) tmp1+=hotly[ansindx]-aray[l];
            else tmp1+=aray[l]-hotly[ansindx];

            if(dist<tmp1) dist=tmp1;
        }
        printf("%d\n%d\n",dist,ansindx+1);
    }
    return 0;
}
