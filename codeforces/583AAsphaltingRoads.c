#include<stdio.h>
#define MAXNUMROAD 51

int main()
{
    int n,h,v;
    int roadh[MAXNUMROAD],roadv[MAXNUMROAD];
    int l,tmp;

    while(1==scanf("%d",&n))
    {
        tmp=n*n;

        for(l=1;l<=n;roadh[l]=1,roadv[l]=1,l++);
        for(l=1;l<=tmp;l++)
        {
            scanf("%d%d",&h,&v);
            if(roadh[h] && roadv[v]){
                printf("%d ",l);
                roadh[h]=0;
                roadv[v]=0;
            }
        }
        putchar('\n');
    }
    return 0;
}
