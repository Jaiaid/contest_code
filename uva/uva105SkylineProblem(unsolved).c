#include<stdio.h>
#define MAXCITYLEN 20004

int main()
{
    int cityheight[MAXCITYLEN];
    int L,H,R;
    int len=0;
    int l;

    for(;EOF!=scanf("%d%d%d",&L,&H,&R);)
    {
        L<<=1,R<<=1;
        if(len<L) for(l=len;l<=R;cityheight[l]=0,l++);
        else if(R>len) for(l=len;l<=R;cityheight[l]=0,l++);

        if(L!=R){
            for(l=L;l<R;l++)
            {
                if(cityheight[l]<H) cityheight[l]=H;
            }
        }
        else if(L==R){
            if(cityheight[L]<=H && cityheight[L-1]<H) cityheight[L]=H;
            else if(cityheight[L]<=H && cityheight[L-1]>=H) cityheight[L]=cityheight[L-1];
            R++;
        }
        if(len<R) len=R;
    }

    for(l=2;l<len;l++)
    {
        if(cityheight[l]!=cityheight[l-1]) printf("%d %d ",l>>1,cityheight[l]);
        else if(l==2) printf("1 0 ");
    }
    printf("%d 0",len>>1);
    return 0;
}
