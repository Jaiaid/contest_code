#include<stdio.h>
#include<stdlib.h>
#define MAXARALEN 500

int comp(const void *arg1,const void *arg2)
{
    return *((int *)arg1)-*((int *)arg2);
}

int main()
{
    int n;
    int gcd[MAXARALEN*MAXARALEN];
    int l,l1,tmp;

    while(1==scanf("%d",&n))
    {
        tmp=n*n;
        for(l=0;l<tmp;scanf("%d",&gcd[l]),l++);

        qsort(gcd,tmp,sizeof(int),comp);

        for(l=1,l1=tmp;l<tmp;)
        {
            if(gcd[l]==gcd[l-1]){
                gcd[l]=0;
                gcd[l-1]=0;
                l1-=2;
                l+=2;
            }
            else{
                l++;
            }
            if(l1==n) break;
        }

        for(l=0;l<tmp;l++)
        {
            if(gcd[l]) printf("%d ",gcd[l]);
        }

        putchar('\n');
    }
    return 0;
}
