#include<stdio.h>

int main()
{
    int n,m;
    int hb[100],hg[100];
    int b,g;
    int l,l1,tmp;

    while(2==scanf("%d%d",&n,&m))
    {
        for(l=0;l<n;hb[l]=0,l++);
        for(l=0;l<m;hg[l]=0,l++);

        scanf("%d",&b);
        for(l=0;l<b;scanf("%d",&tmp),hb[tmp]=1,l++);
        scanf("%d",&g);
        for(l=0;l<g;scanf("%d",&tmp),hg[tmp]=1,l++);

        l1=(n>m)?n:m;
        l1*=l1;
        for(l=0;l<l1;l++)
        {
            if(hg[l%m]) hb[l%n]=1;
            else if(hb[l%n]) hg[l%m]=1;
        }

        for(l=0;hb[l] && l<n;l++);

        if(l==n){
            for(l=0;hg[l] && l<m;l++);
            if(l==m) puts("Yes");
            else puts("No");
        }
        else puts("No");
    }

    return 0;
}
