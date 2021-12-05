#include<stdio.h>

int main()
{
    int n,m;
    while(2==scanf("%d%d",&n,&m))
    {
        int ans;
        if(n<m) ans=-1;
        else{
            if(n&1) ans=((n-1)>>1)+1;
            else ans=n>>1;
            while(ans%m>0 && ans<=n) ans++;
            if(ans>n)ans=-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
