#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	int n,k;
	int ans;
	
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d",&n,&k);
		
		if(k<=n){
			ans = (n%2==k%2)?0:1;
		}
		else{
			ans = k-n;
		}
		printf("%d\n", ans);
		
		t--;
	}
	
	return 0;
}
