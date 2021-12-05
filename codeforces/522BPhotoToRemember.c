#include<stdio.h>
#define MAXARALEN 200000

int main()
{
    int n;
    int w[MAXARALEN],h[MAXARALEN];
    int highest1,highest2,sum;
    int l,tmp;

    while(1==scanf("%d",&n))
    {
        scanf("%d%d",&w[0],&h[0]);

        for(l=1,highest1=h[0],sum=w[0],tmp=0;l<n;l++)
        {
            scanf("%d%d",&w[l],&h[l]);
            if(h[l]>highest1) highest1=h[l],tmp=l;
            sum+=w[l];
        }

        if(!tmp) highest2=h[1];
        else highest2=h[0];

        for(l=0;l<n;l++) if(h[l]>highest2 && l!=tmp) highest2=h[l];

        for(l=0;l<n;l++)
        {
            if(tmp!=l) printf("%d ",(sum-w[l])*highest1);
            else printf("%d ",(sum-w[l])*highest2);
        }
        putchar('\n');
    }
    return 0;
}

