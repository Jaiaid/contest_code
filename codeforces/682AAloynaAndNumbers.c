#include<stdio.h>

int main()
{
	unsigned int n,m;
	int l,tmp,min,max;
	unsigned long long int ans;
	
	while(scanf("%u%u",&n, &m)==2)
	{
		ans=0;
		tmp = n+m;
		if(n<m){
			min=n;
			max=m;
		}
		else{
			min=m;
			max=n;
		}
		
		for(l=5;l<=tmp;l+=5)
		{
			if(l<=min){
				ans+=l-1;
			}
			else if(l<=max){
				ans+=min;
			}
			else{
				ans+=tmp-l+1;
			}
		}
		printf("%llu\n",ans);
	}
	
	return 0;
}
