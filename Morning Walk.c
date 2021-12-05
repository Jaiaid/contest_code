#include<stdio.h>

int main()
{
    int N,R;
    while(2==scanf("%d%d",&N,&R))
    {
        int l,Indeg[N],Outdeg[N];
        for(l=0;l<N;l++) Indeg[l]=0,Outdeg[l]=0;
        for(l=0;l<R;l++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            Outdeg[u]++;
            Indeg[v]++;
        }
        for(l=0;Indeg[l]==Outdeg[l];l++);
        if(l==N) printf("Possible\n");
        else printf("Not Possible\n");
    }
    return 0;
}
