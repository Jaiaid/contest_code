#include<stdio.h>

int main()
{
    long long int n;
    while(1==scanf("%lld",&n))
    {
        long long int sum;
        if(n&1){
            sum=-n;
            sum+=((n-1)>>1);
        }
        else{
            sum=(n>>1);
        }
        printf("%lld\n",sum);
    }

    return 0;
}
