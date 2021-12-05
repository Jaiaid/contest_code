#include<stdio.h>

int main()
{
    int a,m;
    int ara[100000];
    while(2==scanf("%d%d",&a,&m))
    {
        char flag=1;
        int l;
        for(l=0;l<100000;ara[l]=0,l++);
        for(l=0,ara[a%m]++,a%=m;l<100000;l++)
        {
            if(a==0){
                flag=0;
                break;
            }
            a+=a%m;
            a%=m;
            ara[a]++;
            if(ara[a]>1) break;
        }

        if(flag) puts("No");
        else puts("Yes");
    }
    return 0;
}
