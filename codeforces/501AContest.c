#include<stdio.h>

int main()
{
    int a,b,c,d;
    int vscore,mscore;
    while(4==scanf("%d%d%d%d",&a,&b,&c,&d))
    {
        int tmp1,tmp2;
        tmp1=3*a/10,tmp2=a-a*c/250;
        mscore=(tmp1>tmp2)?tmp1:tmp2;

        tmp1=3*b/10,tmp2=b-b*d/250;
        vscore=(tmp1>tmp2)?tmp1:tmp2;

        if(vscore>mscore) puts("Vasya");
        else if(vscore<mscore) puts("Misha");
        else puts("Tie");
    }
    return 0;
}
