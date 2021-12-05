#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<unsigned int>ara;
	int l;
	unsigned int tmp;
	unsigned int ans;
	
	while(scanf("%d",&n)==1)
	{
		for(l=0;l<n;l++)
		{
			scanf("%u",&tmp);
			ara.push_back(tmp);
		}
		
		sort(ara.begin(),ara.end());
		
		for(l=1,ara[0]=1;l<n;l++)
		{
			if(ara[l]>ara[l-1]+1){
				ara[l]=ara[l-1]+1;
			}
		}
		
		if(ara[0]>1){
			ans=ara[0]-1;
		}
		else{
			ans=ara[n-1]+1;
		}
		
		printf("%u\n",ans);
		ara.clear();
	}
	
	return 0;
}
