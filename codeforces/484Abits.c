#include<stdio.h>

unsigned long long int max_num_popcount(unsigned long long int L,unsigned long long int R)
{
    unsigned long long int tmp;
    unsigned long long int l;
    int l1;
    for(l=1,l1=0,tmp=L;(tmp|(l<<l1))<=R;tmp|=(l<<l1),l1++);
    return tmp;
}

int main()
{
    int n;
    unsigned long long int l,r;

    while(1==scanf("%d",&n))
    {
        while(n)
        {
            scanf("%llu%llu",&l,&r);
            printf("%llu\n",max_num_popcount(l,r));
            n--;
        }
    }
    return 0;
}
