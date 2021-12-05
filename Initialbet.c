#include<stdio.h>

int main()
{
    int sum,n,l;
    while(1==scanf("%d",&n))
    {
        sum=0;
        sum+=n;
        for(l=1;l<5;l++)
        {
            scanf("%d",&n);
            sum+=n;
        }

        if(sum%5) printf("-1\n");
        else printf("%d\n",sum/5);
    }

    return 0;
}
