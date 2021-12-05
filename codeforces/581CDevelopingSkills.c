#include<stdio.h>
#include<stdlib.h>
#define MAXNUMSKILL 100000

struct skill
{
    int point;
    int rem;
} skillpoint[MAXNUMSKILL];

int comp(struct skill *arg1,struct skill *arg2)
{
    return arg2->rem-arg1->rem;
}

int main()
{
    int n,k;
    int l;
    int ans;

    while(2==scanf("%d%d",&n,&k))
    {
        ans=0;
        for(l=0;l<n;l++)
        {
            scanf("%d",&skillpoint[l].point);
            skillpoint[l].rem=skillpoint[l].point%10;
        }

        qsort(skillpoint,n,sizeof(struct skill),comp);

        for(l=0;k && l<n;l++)
        {
            if(k<10-skillpoint[l].rem) break;
            if(skillpoint[l].point<100){
                skillpoint[l].point+=(10-skillpoint[l].rem);
                k-=(10-skillpoint[l].rem);
            }
        }
        for(l=0,ans=0;l<n;ans+=(skillpoint[l].point/10),l++);

        if(n*10>ans){
            if(k/10+ans>=n*10) ans=n*10;
            else ans+=(k/10);
        }

        printf("%d\n",ans);
    }
    return 0;
}
