#define MAXOPPONENT 100

#include<stdio.h>

int main()
{
	int n,d;
	char op_presence[MAXOPPONENT+1];
	int l,l1,tmp;
	int ans;

	while(scanf("%d%d",&n,&d)==2)
	{
		for(l=0,ans=0,tmp=0;l<d;l++)
		{
			scanf("%s",op_presence);
			
			for(l1=0;l1<n && op_presence[l1]!='0';l1++);
			
			if(l1<n){
				tmp++;
			}
			else{
				if(tmp>ans) ans=tmp;
				tmp=0;
			}
		}
		if(tmp>ans) ans=tmp;
		
		printf("%d\n",ans);
	}
	return 0;
}
