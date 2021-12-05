#include<stdio.h>

int main()
{
	int T,A,M;
	int tc,tmp,tmp1,l;
	
	scanf("%d",&T);
	
	for(tc=0;tc<T;tc++)
	{
		scanf("%d%d",&A,&M);
		
		tmp=A%M;
		tmp1=0;
		
		for(l=1;l<M && tmp1!=1;l++)
		{
			tmp1+=tmp;
			
			if(tmp1>M) tmp1-=M;
		}
		
		if(tmp1==1) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
