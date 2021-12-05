#include<stdio.h>

int main()
{
    int num_error,error_no;
    int ans1,ans2;
    int l,tmp;

    while(1==scanf("%d",&num_error))
    {
        scanf("%d",&error_no);
        for(l=1;l<num_error;scanf("%d",&tmp),error_no^=tmp,l++);
        for(l=1,ans1=error_no;l<num_error;scanf("%d",&tmp),ans1^=tmp,l++);
        for(l=2,ans2=error_no^ans1;l<num_error;scanf("%d",&tmp),ans2^=tmp,l++);

        printf("%d\n%d\n",ans1,ans2);
    }
    return 0;
}

