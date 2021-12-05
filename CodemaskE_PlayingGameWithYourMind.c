#include<stdio.h>
#include<math.h>

int main()
{
	long long int N;
	int T;
	int tc;
	
	scanf("%d",&T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%lld",&N);
		
		for(;!(N&1);N>>=1);
		
		printf("Case %d: %lld\n",tc,N);
	}
	
	return 0;
}
