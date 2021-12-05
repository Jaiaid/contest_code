#include<stdio.h>

int main()
{
    int tc,ans[40];
    while(1==scanf("%d",&tc))
    {
        int l,N;
        int ara1[200000],ara2[200000];
        for(l=0;l<tc;l++)
        {
            int l1,start1,start2;
            scanf("%d",&N);

            for(l1=0;l1<N;l1++) scanf("%d",ara1+l1);
            for(l1=0;l1<N;l1++) scanf("%d",ara2+l1);
            for(start1=0,start2=0,ans[l]=0;start1<N && start2<N;)
            {
                if(ara1[start1]==ara2[start2]){
                    if(start1<N-1) start1++;
                    if(start2<N-1) start2++;
                }
                else if(ara1[start1]!=ara2[start2] && start1<N){
                    start1++,ans[l]++;
                }
                else if(ara1[start1]!=ara2[start2] && start2<N){
                    start2++,ans[l]++;
                }
                else if(start1==N-1 && start2==N-1){
                    start1++,start2++;
                }
            }

        }
        for(l=0;l<tc;l++) printf("Case %d: %d\n",l+1,ans[l]);
    }
    return 0;
}
