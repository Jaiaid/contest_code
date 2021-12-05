#include<stdio.h>

int main()
{
    int n,x;
    int ara[100];
    int l,l1,strt,ans;

    while(2==scanf("%d%d",&n,&x))
    {
        n<<=1;
        for(l=0;l<n;l+=2) scanf("%d%d",ara+l,ara+l+1);

        for(ans=0,strt=1,l=0;l<n;strt=ara[l+1]+1,l+=2)
        {
            if((ara[l]-strt)/x){
                ans+=(ara[l]-strt)%x;
            }
            else{
                ans+=ara[l]-strt;
            }
            ans+=ara[l+1]-ara[l]+1;
        }
        printf("%d\n",ans);
    }

    return 0;
}
