#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int main()
{
	int n,k, tabs[MAXLEN+1];
	int l,b,sum,tmp[MAXLEN+1];
	int ans;

	while(scanf("%d%d",&n,&k)==2)
	{
		ans=0;
		for(l=1;l<=n;l++) scanf("%d",&tabs[l]);
		
		for(b=1;b<=n;b++)
		{
			memcpy((void *)tmp,(void *)tabs,sizeof(int)*(n+1));
			
			for(l=b;l<=n;l+=k) tmp[l]=0;
			for(l=b-k;l>0;l-=k) tmp[l]=0;
			
			for(l=1,sum=0;l<=n;l++) sum+=tmp[l];
			sum=(sum<0)?-sum:sum;
		       	
			if(sum>ans) ans=sum;
		}

		
		printf("%d\n", ans);
	}
	
	return 0;
}
