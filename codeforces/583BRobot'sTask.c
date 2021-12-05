#include<stdio.h>
#define MAXNUMCOM 1001

int main()
{
    int n;
    int ai[MAXNUMCOM];
    int infpiece,l,l1;
    int dirchg;

    while(1==scanf("%d",&n))
    {
        for(l=1;l<=n;scanf("%d",&ai[l]),l++);
        for(l=0,infpiece=0,dirchg=0;l<n;)
        {
            for(l1=1;l1<=n;l1++)
            {
                if(ai[l1]>=0 && infpiece>=ai[l1]){
                    ai[l1]=-1;
                    infpiece++;
                    l++;
                }
            }
            if(l<n) dirchg++;
            else break;
            for(l1=n;l1;l1--)
            {
                if(ai[l1]>=0 && infpiece>=ai[l1]){
                    ai[l1]=-1;
                    infpiece++;
                    l++;
                }
            }
            if(l<n) dirchg++;
            else break;
        }
        printf("%d\n",dirchg);
    }
    return 0;
}
