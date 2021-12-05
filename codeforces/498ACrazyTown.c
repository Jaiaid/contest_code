#include<stdio.h>

int main(){

    long long int a,b,c;
    int x1,y1,x2,y2;
    int n,tmp1,tmp2;
    int ans;

    while(4==scanf("%d%d%d%d",&x1,&y1,&x2,&y2))
    {
        scanf("%d",&n);
        ans=0;
        while(n)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            tmp1=(a*x1+b*y1+c)>0;
            tmp2=(a*x2+b*y2+c)>0;
            if(tmp1!=tmp2) ans++;
            n--;
        }
        printf("%d\n",ans);
    }

	return 0;
}
