#include<stdio.h>

int main() {

    int T,n;
    int in,out,l,tc,tmp;
    int max;

    scanf("%d",&T);
    for(tc=1;tc<=T;tc++)
    {
        scanf("%d",&n);
        scanf("%d%d",&in,&out);
        for(l=2,tmp=in-out,max=tmp;l<n;l++)
        {
            scanf("%d%d",&in,&out);
            tmp+=in-out;

            if(tmp>max) max=tmp;
        }
        printf("Case %d: %d\n",tc,max);
    }
}
