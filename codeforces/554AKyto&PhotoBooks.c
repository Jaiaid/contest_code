#include<stdio.h>

int main()
{
    char s[21];
    int ans;
    int l;

    while(1==scanf("%s",s))
    {
        for(l=0;s[l];l++);

        ans=(l+1)*(26-l)+l*l;
        printf("%d\n",ans);
    }
    return 0;
}

