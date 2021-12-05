#include<stdio.h>

int main()
{
    int A,B,N;

    while(2==scanf("%d%d",&A,&B))
    {
        int l;
        N=A+B+1;

        for(l=1;l<=A;l++) printf("%d ",l);
        printf("%d ",N);
        for(l=1;B-l>=0;l++) printf("%d ",N-l);
        printf("\n");
    }

    return 0;
}
