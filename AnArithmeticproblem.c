#include<stdio.h>
#include<math.h>

int main()
{

    int T;
    int a1,a2,a3,n;
    int l;

    scanf("%d",&T);

    for(l=1;l<=T;l++)
    {
        scanf("%d%d%d%d",&a1,&a2,&a3,&n);
        if((a2-a1)!=(a3-a2)){
            printf("Case %d: Error\n",l);
        }
        else{
            printf("Case %d: %d\n",l,a1+(a2-a1)*(n-1));
        }
    }

	return 0;
}
