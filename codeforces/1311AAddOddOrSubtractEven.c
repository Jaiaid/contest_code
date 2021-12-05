#include <stdio.h>

int main()
{
	int t, a, b;
	
	scanf("%d", &t);
	while(t)
	{
		scanf("%d%d", &a, &b);
		
		int ans;
		if (a > b) {
			ans = (a%2 == b%2) ? 1 : 2;
		}
		else if (a < b) {
			ans = (a%2 == b%2) ? 2 : 1;
		}
		else {
			ans = 0;
		}
		printf("%d\n",ans);
		t--;
	}
	
	return 0;
}
