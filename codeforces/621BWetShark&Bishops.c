#include<stdio.h>

int main()
{
	int n,x,y;
	int l,l1,ara[4][1002]; 
	int ans;
	
	while(scanf("%d",&n)==1)
	{
		for(l=0;l<4;l++)
		{
			for(l1=1;l1<=1000;l1++) ara[l][l1]=0;
		}
		
		for(l=0;l<n;l++)
		{
			scanf("%d%d",&x,&y);
			
			if(x>y){
				ara[1][x-y+2]++;
				if(y==1) ara[0][x]++;
				
				if(x+y>1001) ara[3][y-(1000-x)]++;
				else if(y!=1) ara[0][x+y-1]++;
			}
			else{
				ara[2][y-x+1]++;
				
				if(x+y>1001) ara[3][y-(1000-x)]++;
				else if(y!=1) ara[0][x+y-1]++;
			}
		}
		
		
		for(ans=0,l=0;l<2;l++)
		{
			for(l1=1;l1<=1000;l1++) ans+=(ara[l][l1]*(ara[l][l1]-1))/2;
		}
		
		for(;l<4;l++)
		{
			for(l1=1;l1<=1000;l1++)
			{
				ans+=(ara[l][l1]*(ara[l][l1]-1))/2;
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
