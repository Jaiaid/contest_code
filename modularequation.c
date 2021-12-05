#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;
    while(2==scanf("%d%d",&a,&b))
    {
        if(a==b){
            puts("infinity");
        }
        else{
            int l,ans,rng;
            a-=b;

            for(l=1,ans=0,rng=sqrt(a);l<=rng;l++)
            {
                if(a%l==0){
                    int tmp=a/l;
                    if(l>b) ans++;
                    if(l!=tmp && tmp>b) ans++;
                }
            }

            printf("%d\n",ans);
        }
    }
    return 0;
}
