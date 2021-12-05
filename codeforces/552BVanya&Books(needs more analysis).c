#include<stdio.h>

int main()
{
    long long int n,total_digit;
    long long int sub;

    while(1==scanf("%lld",&n))
    {
        for(total_digit=n,sub=10;n-sub+1>0;sub*=10)
        {
            total_digit+=(n-sub+1);
        }

        printf("%lld\n",total_digit);
    }

    return 0;
}

