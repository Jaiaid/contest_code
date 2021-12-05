#include<stdio.h>
#include<stdlib.h>

int comp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int N,vote[100];
    int l;
    int ans;

    while(1==scanf("%d",&N))
    {
        for(l=0;l<N;l++) scanf("%d",&vote[l]);
        ans=vote[0];

        qsort(&vote[1],N-1,4,comp);
        while(ans<=vote[1])
        {
            vote[1]--;
            ans++;
            qsort(&vote[1],N-1,4,comp);
        }

        printf("%d\n",ans-vote[0]);
    }

    return 0;
}

