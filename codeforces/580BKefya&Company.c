#define MAXLEN 100000
#include<stdio.h>
#include<stdlib.h>

struct person{
    long long int m;
    long long int s;
} friends[MAXLEN];

int comp(struct person *arg1,struct person *arg2)
{
    return arg1->m-arg2->m;
}

int main()
{
    int n;
    unsigned long long int d;
    int l,ini;
    long long int tmp;
    long long int maxff;

    while(2==scanf("%d%lld",&n,&d))
    {
        for(l=0;l<n;l++) scanf("%lld%lld",&friends[l].m,&friends[l].s);

        qsort(friends,n,sizeof(struct person),comp);

        for(l=1,tmp=friends[0].s,ini=0,maxff=0;l<n;l++)
        {
            if(friends[l].m<friends[ini].m+d) tmp+=friends[l].s;
            else{
                if(tmp>maxff) maxff=tmp;
                while(friends[l].m>=friends[ini].m+d) tmp-=friends[ini].s,ini++;
                tmp+=friends[l].s;
            }
        }
        if(tmp>maxff) maxff=tmp;
        printf("%lld\n",maxff);
    }
    return 0;
}
