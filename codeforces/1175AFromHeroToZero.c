#include <stdio.h>

int main()
{
	int tc; 
	unsigned long long int n, k;
	int l;
	unsigned long long int step;
	
	scanf("%d",&tc);
	for(l=0;l<tc;l++) 
	{
		scanf("%llu%llu",&n,&k);
		
		for(step=0;n>0;)
		{
			if(n%k==0){
				n/=k;
				step++;
			}
			else{
				step+=n%k;
				n-=(n%k);
			}
		}
		
		printf("%llu\n",step);
	}
	
	return 0;
}
