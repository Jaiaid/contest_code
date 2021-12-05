#include <stdio.h>

int main()
{
	int h,w,u1,d1,u2,d2;
	int l;
	int ans;
	
	while(scanf("%d%d",&w,&h)==2)
	{
		scanf("%d%d",&u1,&d1);
		scanf("%d%d",&u2,&d2);
		
		for(l=h,ans=w;l>0;l--)
		{
			ans+=l;
			if(l==d1) ans-=u1;
			else if(l==d2) ans-=u2;
			if(ans<0) ans = 0;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
