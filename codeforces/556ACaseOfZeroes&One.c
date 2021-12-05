#include<stdio.h>

int main()
{
    char s[200000];
    int n;
    int ans;
    int l;

    while(1==scanf("%d",&n))
    {
        scanf("%s",s);
        for(l=0,ans=0;s[l];l++) s[l]=='0'?ans++:ans--;

        if(ans<0) ans=-ans;
        printf("%d\n",ans);
    }
    return 0;
}

