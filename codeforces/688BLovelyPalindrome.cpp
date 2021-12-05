#define MAXLEN 200010

#include<stdio.h>

int main()
{
	char n[MAXLEN+1];
	int l,l1;

	while(scanf("%s",n)==1)
	{
		for(l=0;n[l];l++);
		l1=l;
		for(l--;l>=0;l--,l1++)
		{
			n[l1]=n[l];
		}
		n[l1]='\0';
		puts(n);
	}
	return 0;
}
