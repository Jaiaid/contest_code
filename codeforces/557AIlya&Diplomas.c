#include<stdio.h>

int main()
{
    int n,min1,min2,min3,max1,max2,max3;
    int l,tmp;

    while(1==scanf("%d",&n))
    {
        scanf("%d%d%d%d%d%d",&min1,&max1,&min2,&max2,&min3,&max3);

        tmp=min1+min2+min3;

        l=min1;
        if(tmp+max1-l<=n) l=max1;
        else l+=n-tmp;
        printf("%d ",l);
        tmp+=l-min1;

        l=min2;
        if(tmp+max2-l<=n) l=max2;
        else l+=n-tmp;
        printf("%d ",l);
        tmp+=l-min2;

        l=min3;
        if(tmp+max3-l<=n) l=max3;
        else l+=n-tmp;
        printf("%d\n",l);
        tmp+=l-min3;
    }
    return 0;
}

