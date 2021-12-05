#include <stdio.h>
#include <string.h>

#define MAXLEN 101

int main()
{
	int t;
	char b[MAXLEN+1];
	int l;
	
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%s",b);
		
		b[strlen(b)+1] = '\0';
		putchar(b[0]);
		for(l=1;b[l]!='\0';l+=2)
		{
			putchar(b[l]);
		}
		putchar('\n');
		
		t--;
	}
	
	return 0;
}
