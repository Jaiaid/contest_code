#include<stdio.h>

int main()
{
    long long int a,b,s;
    while(3==scanf("%lld%lld%lld",&a,&b,&s))
    {
        if(a<0) a=-a;
        if(b<0) b=-b;

        if(a+b==s) puts("Yes");
        else if(a+b<s && !((s-a-b)&1)) puts("Yes");
        else puts("No");
    }
    return 0;
}
