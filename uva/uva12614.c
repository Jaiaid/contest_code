#include<stdio.h>

int main()
{
    int tc,case_no=0;
    int l,tmp;
    int ans;

    scanf("%d",&tc);
    while(tc)
    {
        scanf("%d",&l);

        scanf("%d",&ans);
        for(l--;l;l--)
        {
            scanf("%d",&tmp);
            if(tmp>ans) ans=tmp;
        }

        printf("Case %d: %d\n",++case_no,ans);

        tc--;
    }
    return 0;
}
