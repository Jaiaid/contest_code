#include<stdio.h>

int main()
{
    int n,l;
    int ara[3000];
    int ansara[6000];
    while(1==scanf("%d",&n))
    {
        int swap=0;
        for(l=0;l<n;l++) scanf("%d",ara+l);
        for(l=0;l<n;l++)
        {
            int min,l1;
            for(l1=l+1,min=l;l1<n;l1++)
            {
                if(ara[l1]<ara[min]) min=l1;
            }

            if(min!=l){
                l1=ara[l];
                ara[l]=ara[min];
                ara[min]=l1;
                ansara[swap*2]=l;
                ansara[swap*2+1]=min;
                swap++;
            }
        }
        printf("%d\n",swap);
        for(l=0,swap*=2;l<swap;l+=2) printf("%d %d\n",ansara[l],ansara[l+1]);

    }
    return 0;
}
