#include<stdio.h>

unsigned int f(int n1,int n2,int n3)
{
    unsigned int ara[3],tmp;
    int l,l1;

    ara[0]=n1,ara[1]=n2,ara[2]=n3;

    for(l=0;l<3;l++)
    {
        for(l1=1;l1<3-l;l1++)
        {
            if(ara[l1]<ara[l1-1]){
                tmp=ara[l1];
                ara[l1]=ara[l1-1];
                ara[l1-1]=tmp;
            }
        }
    }

    if(ara[0]==ara[1] && ara[2]>=ara[1]) return ara[0]*3;
    else if(ara[0]!=ara[1] && ara[2]!=ara[1]) return (ara[1]<<1)+ara[0];
    else if(ara[1]==ara[2]) return (ara[2]<<1)+ara[0];
}
int main()
{
    int n1,n2,n3;
    while(3==scanf("%d%d%d",&n1,&n2,&n3))
    {
        printf("%u\n",f(n1,n2,n3));
    }
    return 0;
}
