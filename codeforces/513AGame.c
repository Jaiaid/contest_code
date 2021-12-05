#include<stdio.h>
#define MAXCITYLEN 20004

int main()
{
    int n1,n2,k1,k2;
    int turn;
    int l;

    while(4==scanf("%d%d%d%d",&n1,&n2,&k1,&k2))
    {
        for(turn=1;n1 && n2;)
        {
            if(turn==1) n1--;
            else n2--;

            if(turn==1) turn=2;
            else turn=1;
        }

        if(turn==2) puts("Second");
        else puts("First");
    }
    return 0;
}
