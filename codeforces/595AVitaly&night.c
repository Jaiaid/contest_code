#include<stdio.h>

int main()
{
	int n,m;
	int l,l1,tmp,tmp1;
	int ans;
	
	while(2==scanf("%d%d",&n,&m))
	{
		for(l=0,ans=0;l<n;l++)
		{
			for(l1=0;l1<m;l1++)
			{
				scanf("%d%d",&tmp,&tmp1);
				if(tmp || tmp1) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


