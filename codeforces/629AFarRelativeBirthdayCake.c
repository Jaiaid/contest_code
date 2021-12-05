#include<stdio.h>

#define MAXLEN 101

int main()
{
	char cake[MAXLEN][MAXLEN];
	int n;
	int l,l1,tmp,tmp1;
	int ans;
	
	while(scanf("%d",&n)==1)
	{	
		for(l=0;l<n;l++) scanf("%s",cake[l]);
		
		for(ans=0,l=0;l<n;l++)
		{
			for(l1=0,tmp=0,tmp1=0;l1<n;l1++)
			{
				if(cake[l][l1]=='C') tmp++;
				if(cake[l1][l]=='C') tmp1++;
			}
			
			ans+=tmp*(tmp-1)/2+tmp1*(tmp1-1)/2;
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
