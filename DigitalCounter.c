#include<stdio.h>

int main()
{
    int ara[10]={2,7,2,3,3,4,2,5,1,2};
    char num[3];
    while(1==scanf("%s",num))
    {
        num[0]-=48;
        num[1]-=48;
        printf("%d\n",ara[num[0]]*ara[num[1]]);
    }
    return 0;
}
