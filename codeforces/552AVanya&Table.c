#include<stdio.h>

int main()
{
    int n;
    int x1,y1,x2,y2;
    int value;
    int l;
    while(1==scanf("%d",&n))
    {
        for(l=0,value=0;l<n;l++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            value+=(x2-x1+1)*(y2-y1+1);
        }
        printf("%d\n",value);
    }

    return 0;
}

