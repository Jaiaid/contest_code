#include<stdio.h>
#define MAXHOUSE 100000

int main()
{
    int n;
    int house[MAXHOUSE];
    int l,tmpmax;
    int ans[MAXHOUSE];

    while(1==scanf("%d",&n))
    {
        for(l=0;l<n;scanf("%d",&house[l]),l++);
        for(l=n-1,tmpmax=0;l>=0;l--)
        {
            if(house[l]<tmpmax) ans[l]=tmpmax-house[l]+1;
            else if(house[l]==tmpmax) ans[l]=1;
            else{
                ans[l]=0;
                tmpmax=house[l];
            }
        }
        for(l=0;l<n;l++) printf("%d ",ans[l]);
        putchar('\n');
    }
    return 0;
}
