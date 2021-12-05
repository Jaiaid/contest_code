#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	int a,b,n;
	int tmp;
	int ans;
	
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d%d%d",&a,&b,&n);
		
		ans=0;
		tmp=0;
		if(a<b){
			tmp=a;
			a=b;
			b=tmp;
		}
		
		do
		{
			tmp=a+b;
			b=a;
			a=tmp;
			ans++;
		}
		while(a<=n);
		
		printf("%d\n",ans);
		T--;
	}
	
	return 0;
}
