#include<stdio.h>
#include<math.h>

int main()
{

    int T;
    int l,l1;
    int N;
    double bi,ans;

    scanf("%d",&T);

    for(l=0;l<T;l++)
    {
        scanf("%d",&N);

        ans=0;

        for(l1=0;l1<N;l1++)
        {
            scanf("%lf",&bi);
            ans+=bi;
        }
        ans/=N;
        printf("%.6lf\n",ans);
    }

	return 0;
}
