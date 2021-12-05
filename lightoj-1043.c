#include<stdio.h>
#include<math.h>

int main()
{
    int tc,case_no=0;
    double ab,bc,ac;
    double ratio;

    scanf("%d",&tc);

    while(case_no<tc)
    {
        scanf("%lf%lf%lf%lf",&ab,&bc,&ac,&ratio);

        ratio=1/sqrt(1/ratio+1);

        printf("Case %d: %lf\n",++case_no,ab*ratio);
    }
    return 0;
}

