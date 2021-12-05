#include<stdio.h>

int main()
{
    int N,p,sum,hr,ans;
    int l,l1;

    while(2==scanf("%d%d",&N,&p))
    {
        for(l=0,sum=0;l<p;l++)
        {
            scanf("%d",&hr);
            sum+=hr;
        }

        ans=N/sum;
        N-=(N/sum)*sum;
        if(N%sum) ans++;

        if(ans==1)printf("Project will finish within 1 day.\n");
        else printf("Project will finish within %d days.\n",ans);
    }
    return 0;
}
