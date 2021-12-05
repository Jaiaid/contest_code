#include<stdio.h>

int main()
{
    char pass[101];
    int l,flg1,flg2,flg3;
    int count;

    while(1==scanf("%s",pass))
    {
        for(l=0,count=0,flg1=0,flg2=0,flg3=0;pass[l];l++)
        {
            if('0'<=pass[l] && pass[l]<='9') flg1=1;
            else if('a'<=pass[l] && pass[l]<='z') flg2=1;
            else flg3=1;

            if(flg1 && flg2 && flg3) count++,flg1=0,flg2=0,flg3=0;
        }

        printf("%d\n",count);
    }
    return 0;
}

