#include<stdio.h>

int main()
{
    int n,t;
    int ara[30001];
    int l,temp;

    while(2==scanf("%d%d",&n,&t))
    {

        for(l=1;l<n;scanf("%d",&ara[l]),l++);

        for(l=1,temp=1;l<n,temp<t;l=temp)
        {
            temp=temp+ara[l];
        }

        if(temp==t) puts("YES");
        else puts("NO");
    }
    return 0;
}
