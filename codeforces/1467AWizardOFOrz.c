#include <stdio.h>

int main()
{
	int t;
	int n;
	
	scanf("%d",&t);
	while(t>0)
	{
		char c='8';
		int l;
		
		scanf("%d",&n);
		
		putchar('9');
		for(l=1;l<n;l++)
		{
			putchar(c);
			c=(c!='9')?c+1:'0';
		}
		putchar('\n');
		t--;
	}
	
	return 0;
}
