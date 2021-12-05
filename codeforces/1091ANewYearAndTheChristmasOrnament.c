#include <stdio.h>

int main()
{
	int y,b,r;
	char decisionC;
	int ans;
	
	while(scanf("%d%d%d",&y,&b,&r)==3)
	{
		decisionC = 'r';
		if(y<=b-1 && y<=r-2) decisionC = 'y';
		else if(b<=y+1 && b<=r-2) decisionC = 'b';
		
		if(decisionC=='r') ans = 3*r-3;
		else if(decisionC=='b') ans = 3*b;
		else ans = 3*y+3;
		
		printf("%d\n", ans);
	}
	
	return 0;
}
