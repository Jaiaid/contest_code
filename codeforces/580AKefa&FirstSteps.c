#define MAXLEN 100000
#include<stdio.h>

int main()
{
    int n,ara[MAXLEN];
    int l,tmp;
    int len;

    while(1==scanf("%d",&n))
    {
        scanf("%d",&ara[0]);
        for(l=1,tmp=1,len=0;l<n;l++)
        {
            scanf("%d",&ara[l]);

            if(ara[l]>=ara[l-1]) tmp++;
            else{
                if(tmp>len) len=tmp;
                tmp=1;
            }
        }
        if(tmp>len) len=tmp;
        printf("%d\n",len);
    }
    return 0;
}
