#include<stdio.h>

int main()
{
    int n,k;
    int a[100];
    int l,l1,l2;
    while(2==scanf("%d%d",&n,&k))
    {
        for(l=0;l<n;scanf("%d",&a[l]),l++);
        for(l=0;l<n;l++)
        {
            for(l1=0;l1<n;l1++)
            {
                if((a[l]-a[l1])<-k || (a[l]-a[l1])>k){
                    puts("NO");
                    break;
                }
            }
            if(l1!=n) break;
        }

        if(l==n){
            puts("YES");
            for(l=0;l<n;l++)
            {
                for(l1=1,l2=0;l2<a[l];l1++,l2++)
                {
                    if(l1==k+1) l1=1;
                    printf("%d ",l1);
                }
                putchar('\n');
            }
        }

    }
    return 0;
}
