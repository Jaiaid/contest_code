#include<stdio.h>

int main()
{
    long long int a,b;
    long long int n;
    while(2==scanf("%lld%lld",&a,&b))
    {
        for(n=0;a && b;)
        {
            if(a>b) n+=a/b,a=a%b;
            else n+=b/a,b=b%a;
        }
        printf("%lld\n",n);
    }
    return 0;
}

