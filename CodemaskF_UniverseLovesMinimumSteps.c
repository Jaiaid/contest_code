#include<cstdio>
#include<algorithm>

#define ARALEN 100

using namespace std;

int main()
{
	int T,N,ara[ARALEN];
	int tc,l,l1;
	int ans;
	
	scanf("%d",&T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d",&N);
		
		for(l=0;l<N;l++) scanf("%d",&ara[l]);
		
		sort(ara,ara+N);
		
		for(l=0;ara[l]==0 && l<N;l++);
		
		for(ans=0;l!=N;ans++)
		{
			for(l1=0;ara[l1]<0 && l1<N;l1++) ara[l1]++;
			for(;ara[l1]==0 && l1<N;l1++);
			for(;ara[l1]>0 && l1<N;l1++) ara[l1]--;
			
			for(l=0;ara[l]==0 && l<N;l++);
		}
		
		printf("Case %d: %d\n",tc,ans);
	}
	
	return 0;
}
