#include <stdio.h>

#define MAXLEN 100

int main()
{
	int t,n,k;
	char c;
	int l;
	char s[MAXLEN+1];
	
	scanf("%d", &t);
	
	while(t)
	{
		scanf("%d%d", &n, &k);
		
		c='a';
		for(l=0;l<n;l++)
		{	
			s[l]=c;
			c++;
			if(c>='a'+k) c='a';
		}
		s[n] = '\0';
		
		printf("%s\n", s);
		t--;
	}
	
	return 0;
}
