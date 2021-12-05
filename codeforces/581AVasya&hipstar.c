#include<stdio.h>

int main()
{
    int a,b;
    int min,max;
    while(2==scanf("%d%d",&a,&b))
    {
        min=(a<b)?a:b;
        max=(a^b)^min;
        max-=min;
        printf("%d %d\n",min,max>>1);
    }
    return 0;
}
