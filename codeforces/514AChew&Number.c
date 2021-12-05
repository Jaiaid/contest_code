#include<stdio.h>

int main()
{
    char num[30];
    int l;

    while(1==scanf("%s",num))
    {
        l=0;
        if(num[0]=='9') l=1;
        for(;num[l];l++) if('9'-num[l]<5) num[l]='9'-num[l]+'0';

        puts(num);
    }
    return 0;
}
