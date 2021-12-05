#include<stdio.h>

typedef struct{
    int x;
    int a;
} tree;

int main()
{
    tree ara[100];
    int n;
    int ans;
    int l,l1,tmp,dir;
    tree tmpt;

    while(1==scanf("%d",&n))
    {
        ara[0].x=0,ara[0].a=0;
        for(l=1;l<=n;l++) scanf("%d%d",&ara[l].x,&ara[l].a);

        for(l=0,n++;l<n;l++)
        {
            tmp=n-l;
            for(l1=1;l1<tmp;l1++)
            {
                if(ara[l1].x<ara[l1-1].x){
                    tmpt=ara[l1];
                    ara[l1]=ara[l1-1];
                    ara[l1-1]=tmpt;
                }
            }
        }

        for(l=0;ara[l].x<0 && l<n;l++);

        if(l==n) l--,dir=-1;
        else{
            dir=-1;
            if(l<n/2) dir=1;
        }

        for(ans=0,l+=dir;l>=0 && l<n;l+=dir)
        {
            if(dir<0) ans+=ara[l].a,dir--;
            else ans+=ara[l].a,dir++;

            dir=-dir;
        }

        printf("%d\n",ans);
    }
    return 0;
}

