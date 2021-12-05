#include<stdio.h>

unsigned int modpow(unsigned int V,unsigned int exp)
{
    unsigned int mul=1;
    unsigned int rem=V%1000000007;

    while(exp)
    {
        if(!(exp&1))
        {
            rem=(rem*rem)%1000000007;
            exp>>=1;
        }
        mul*=rem;
        mul%=1000000007;
        exp--;
    }

    return mul;
}

int main()
{
    unsigned int tc,ans[500];
    while(1==scanf("%u",&tc))
    {
        int l;
        for(l=0; l<tc; l++)
        {
            unsigned int D,V,sum=0,mul;
            scanf("%u%u",&D,&V);
            if(V!=1) sum+=(modpow(V,D+1)-1)/((V-1)%1000000007);
            else sum+=((D%1000000007)*(V%1000000007)+1)%1000000007;
            ans[l]=sum;
        }

        for(l=0; l<tc; l++) printf("Case %u: %u\n",l+1,ans[l]);
    }

    return 0;
}
