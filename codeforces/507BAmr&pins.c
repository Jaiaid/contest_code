#include<stdio.h>
#include<math.h>

int main()
{

    int r,x,y,x1,y1;
    double dist;
    int d_twice;
    int d;
    int ans;

    while(5==scanf("%d%d%d%d%d",&r,&x,&y,&x1,&y1))
    {
        dist=sqrt((1.0*x-x1)*(1.0*x-x1)+(1.0*y-y1)*(1.0*y-y1));
        d=r<<1;

        ans=((int)dist)/d;
        dist-=ans*d;
        if(dist){
            while(dist>0) ans++,dist-=d;
        }

        printf("%d\n",ans);
    }

	return 0;
}
