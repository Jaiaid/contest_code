#include<stdio.h>

int main()
{
    int tc,n;
    int l;

    scanf("%d",&tc);
    while(tc)
    {
        scanf("%d",&n);
        if(n>=0){
            for(l=1,putchar('0');l<=n;l++) printf(" %d",l);
        }
        else{
            for(l=n+1,printf("%d",n);l<=0;l++) printf(" %d",l);
        }
        tc--;
        putchar('\n');
    }
}
