#include<stdio.h>

#define MAXSTREET 100
#define MAXAVE 100

int main()
{
	unsigned int n,m,city[MAXSTREET][MAXAVE];
	unsigned int l,l1,tmp,tmp1,max;
	unsigned int ans;
	
	while(2==scanf("%u%u",&n,&m))
	{
		for(l=0;l<n;l++)
		{
			for(l1=0;l1<m;l1++) scanf("%u",&city[l][l1]);
		}
		
		for(l=0,tmp=0,max=0;l<n;l++)
		{
			for(l1=1,tmp1=city[l][0];l1<m;l1++)
			{
				if(city[l][l1]<tmp1) tmp1=city[l][l1];
			}
		
			if(max<tmp1){
				max=tmp1;
				tmp=l;
			}
		}
		
		for(l1=1,ans=city[tmp][0];l1<m;l1++)
		{
			if(city[tmp][l1]<ans) ans=city[tmp][l1];
		}
		
		printf("%u\n",ans);
	}
	
	return 0;
}
