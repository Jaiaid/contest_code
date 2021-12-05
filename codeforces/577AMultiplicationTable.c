#include<stdio.h>

int main()
{
    int n,x;
    int l;
    int ans;

    while(2==scanf("%d%d",&n,&x))
    {
        for(l=1,ans=0;l<=n;l++)
        {
            if(x%l==0 && x/l<=n) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
