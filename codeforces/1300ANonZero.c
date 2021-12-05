#include <stdio.h>

#define MAXLEN 100

int main()
{
	int t, n;
	int i, tmp, sum, zero_count;
	int ans;
	
	scanf("%d", &t);
	while(t)
	{
		scanf("%d", &n);
		
		ans=0;
		sum=0;
		zero_count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d", &tmp);
			sum+=tmp;
			if(tmp==0){
				zero_count++;
			}
		}
		
		if(zero_count>0){
			ans+=zero_count;
			sum+=zero_count;
		}
		if(sum==0){
			ans++;
		}
		printf("%d\n",ans);
		
		t--;
	}
	
	return 0;
}
