#include<stdio.h>
#define ARALEN 10001

int main()
{
    int marble[ARALEN];
    int n,q;
    int caseno=1,marble_no;
    int l,l1,tmp,max_marble_no;

    while(2==scanf("%d%d",&n,&q))
    {
        if(n || q){
            for(l=0;l<ARALEN;marble[l]=0,l++);

            for(l=0,max_marble_no=0;l<n;l++)
            {
                scanf("%d",&tmp);
                marble[tmp]++;
                if(max_marble_no<tmp) max_marble_no=tmp;
            }

            for(tmp=0,l=1;l<=max_marble_no;l++)
            {
                if(marble[l]){
                    marble[l]+=tmp;
                    tmp=marble[l];
                }
            }

            printf("CASE# %d:\n",caseno++);
            for(l=0;l<q;l++)
            {
                scanf("%d",&marble_no);

                if(marble[marble_no]){
                    for(l1=marble_no-1;l1 && !marble[l1];l1--);
                    printf("%d found at %d\n",marble_no,marble[l1]+1);
                }
                else printf("%d not found\n",marble_no);
            }
        }
        else break;
    }
    return 0;
}

