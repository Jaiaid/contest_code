#include<stdio.h>

#define MAXBULB 100

int main()
{
	int n,m,ara[MAXBULB+1];
	int l,l1,tmp;

	scanf("%d%d",&n,&m);

	for(l=1;l<=m;ara[l]=0,l++);

	for(l=0;l<n;l++)
	{
		scanf("%d",&l1);
		for(;l1;l1--)
		{
			scanf("%d",&tmp);
			ara[tmp]=1;
		}
	}

	for(l=1;l<=m && ara[l];l++);

	if(l>m) puts("YES");
	else puts("NO");

	return 0;
}
