#include <stdio.h>

int main()
{
	int t;
	int n;
	
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d",&n);
		
		if(n%4==0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		t--;
	}
	
	return 0;
}
