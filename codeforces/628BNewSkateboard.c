#include<stdio.h>
#include<string.h>

#define MAXLEN 300001

int main()
{
	char str[MAXLEN];
	int l,tmp;
	unsigned long long int ans;
	
	while(scanf("%s",str)==1)
	{	
		for(ans=0,l=strlen(str)-1;l>=0;l--)
		{
			tmp=str[l]-'0';
			
			if(tmp%2){
				continue;
			}
			
			if(tmp%4==0) ans++;
			
			if(l==0) continue;
			
			tmp+=(str[l-1]-'0')*10;
			
			if(tmp%4==0) ans+=l;
		}
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
