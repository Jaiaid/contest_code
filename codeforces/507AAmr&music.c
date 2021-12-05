#include<stdio.h>

struct instrument{
    int day;
    int index;
};

int main(){

    struct instrument ara[100],tmp1;
    int n,k;
    int l,l1;
    int ans,tmp;

    while(2==scanf("%d%d",&n,&k))
    {
        for(l=0;l<n;l++) scanf("%d",&ara[l].day),ara[l].index=l+1;

        for(l=0;l<n;l++)
        {
            tmp=n-l-1;
            for(l1=0;l1<tmp;l1++)
            {
                if(ara[l1].day>ara[l1+1].day){
                    tmp1=ara[l1+1];
                    ara[l1+1]=ara[l1];
                    ara[l1]=tmp1;
                }
            }
        }

        for(l=0,ans=0;ara[l].day<=k && l<n;ans++,l++,ara[l].day+=ara[l-1].day);
        n=l;

        printf("%d\n",ans);
        for(l=0;l<n;l++) printf("%d ",ara[l].index);
        if(n) putchar('\n');

    }

	return 0;
}
