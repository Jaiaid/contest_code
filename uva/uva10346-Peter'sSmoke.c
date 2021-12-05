#include<stdio.h>

int main()
{
    int n,k;
    int ans;
    int tmpq,tmpr;

    while(2==scanf("%d%d",&n,&k))
    {
        ans=0;

        while(n>=k)
        {
            tmpq=n/k;
            tmpr=n/r;
            ans+=n-tmpr;
            n=tmpr+tmpq;
        }
        ans+=n;
        printf("%d\n",ans);
    }
    return 0;
}
