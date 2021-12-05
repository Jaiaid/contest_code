#include<stdio.h>

#define MAXLEN 100000

int main()
{
	unsigned char str[MAXLEN];
	int len;
	int l,ara[26],temp,temp1;
	int ans;
	
	while(scanf("%d",&len)==1)
	{
		scanf("%s",str);
		if(len>26){
			puts("-1");
			continue;
		}
		
		for(l=0;l<26;l++)
		{
			ara[l]=0;
		}
		
		for(l=0;str[l];l++)
		{
			ara[str[l]-'a']++;
		}
		
		for(temp=0,l=0;l<26;l++)
		{
			if(ara[l]){
				temp++;
			}
		}
		
		for(temp1=0,l=0;l<26;l++)
		{
			if(ara[l]>1){
				temp1+=ara[l]-1;
			}
		}
		
		if(temp1+temp>26){
			ans=-1;
		}
		else{
			ans=temp1;
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
