#include<stdio.h>

char number[20][10]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char number1[10][10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

int main()
{
    int n;

    while(1==scanf("%d",&n))
    {
        if(n<20) puts(number[n]);
        else{
            printf("%s",number1[n/10]);
            if(n%10) printf("-%s",number[n%10]);
            putchar('\n');
        }
    }

    return 0;
}


