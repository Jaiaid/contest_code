#include<stdio.h>

#define MAXFRIEND 5000
#define YEARLEN 366

struct frnd{
	int firstday;
	int lastday;
}; 

int main()
{
	int n;
	struct frnd male[MAXFRIEND],female[MAXFRIEND];
	char gender[2];
	int l,tmp,tmp1,tmpmin,tmpmin1,day;
	int ans;
	
	while(scanf("%d",&n)==1)
	{	
		for(l=0,tmp=0,tmp1=0;l<n;l++)
		{
			scanf("%s",gender);
			
			if(gender[0]=='M'){
				scanf("%d%d",&male[tmp].firstday,&male[tmp].lastday);
				tmp++;
			}
			else{
				scanf("%d%d",&female[tmp1].firstday,&female[tmp1].lastday);
				tmp1++;
			}
		}
		
		
		for(ans=0,day=1;day<=YEARLEN;day++)
		{
			for(l=0,tmpmin=0;l<tmp;l++)
			{
				if(male[l].firstday<=day && day<=male[l].lastday) tmpmin++;
			}
			for(l=0,tmpmin1=0;l<tmp1;l++)
			{
				if(female[l].firstday<=day && day<=female[l].lastday) tmpmin1++;
			}
			
			tmpmin=(tmpmin<tmpmin1)?tmpmin:tmpmin1;
			
			if(ans<tmpmin) ans=tmpmin;
		}
		
		printf("%d\n",ans*2);
	}
	
	return 0;
}
