#include<stdio.h>

#define MAXBUYER 40
#define MAXLEN 10

int main()
{
	char buyer_desc[MAXBUYER][MAXLEN];
	int n,p;
	int l;
	unsigned long long int tmp;
	unsigned long long int ans;
	
	scanf("%d%d",&n,&p);
	
	for(l=0;l<n;l++) scanf("%s",buyer_desc[l]);
	
	for(l--,tmp=0,ans=0;l>=0;l--)
	{
		if(buyer_desc[l][4]=='p'){
			tmp=tmp*2+1;
			ans=ans+p/2+(tmp-1)*p/2;
		}
		else{
			tmp=tmp*2;
			ans=ans+tmp*p/2;
		}
	}
	
	printf("%llu\n",ans);
	
	return 0;
}
