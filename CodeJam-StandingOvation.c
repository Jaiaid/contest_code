#include<stdio.h>

int main()
{
    int tc,n;
    int l,ans;
    int sum,tmp=0;
    char Smax[1001];
    scanf("%d",&tc);
    while(tmp<tc)
    {
        scanf("%d%s",&n,Smax);
        for(l=1,ans=0,sum=Smax[0]-48;Smax[l];l++)
        {
            if(sum<l) ans+=l-sum,sum+=Smax[l]-48+l-sum;
            else sum+=Smax[l]-48;
        }

        printf("Case #%d: %d\n",++tmp,ans);
    }
    return 0;
}

