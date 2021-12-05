#include<stdio.h>

int main()
{
	int n;
	long long int input;
	int l;
	long long int tmpmin;
	long long int sum;
	
	while(scanf("%d",&n)==1)
	{
		for(l=0,sum=0,tmpmin=1000000000;l<n;l++)
		{
			scanf("%lld",&input);
			sum+=input;
			
			if(input&1 && input<tmpmin){
				tmpmin=input;
			}
		}
		
		if(sum&1) printf("%lld\n",sum-tmpmin);
		else printf("%lld\n",sum);
	}
	
	return 0;
}
