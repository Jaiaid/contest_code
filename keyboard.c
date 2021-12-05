#include<stdio.h>

int main()
{
    char str[]="qwertyuiopasdfghjkl;zxcvbnm,./";
    char input[101];
    char shift;
    while(2==scanf("%c%s",&shift,input))
    {
        int n,l;
        if(shift=='R') n=-1;
        else n=1;

        for(l=0;input[l];l++)
        {
            int l1;
            for(l1=0;str[l1]!=input[l];l1++);
            input[l]=str[l1+n];
        }
        puts(input);
        getchar();
    }
    return 0;
}
