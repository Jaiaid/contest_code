#include<stdio.h>

int main()
{

    int n,m,k;
    char ara[1002][1002];
    int movesx,movesy;
    int l,l1,flag,ans;

    while(3==scanf("%d%d%d",&n,&m,&k))
    {
        n+=2;
        for(l=0;l<n;l++)
        {
            for(l1=0;l1<n;ara[l][l1]=0,l1++);
        }

        for(l=0,ans=0,flag=0;l<k;l++)
        {
            scanf("%d%d",&movesx,&movesy);

            ara[movesx][movesy]=1;

            if(ara[movesx-1][movesy-1] && ara[movesx-1][movesy] && ara[movesx][movesy-1]){
                if(!flag) ans=l+1;
                flag=1;
            }
            else if(ara[movesx][movesy+1] && ara[movesx+1][movesy+1] && ara[movesx+1][movesy]){
                if(!flag) ans=l+1;
                flag=1;
            }
            else if(ara[movesx][movesy-1] && ara[movesx+1][movesy-1] && ara[movesx+1][movesy]){
                if(!flag) ans=l+1;
                flag=1;
            }
            else if(ara[movesx][movesy+1] && ara[movesx-1][movesy] && ara[movesx-1][movesy+1]){
                if(!flag) ans=l+1;
                flag=1;
            }
        }

        printf("%d\n",ans);

    }
	return 0;
}
