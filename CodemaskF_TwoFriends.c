#include<stdio.h>
#include<math.h>

int main()
{
	int T,N;
	int tc;
	
	scanf("%d",&T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d",&N);
		
		if(N<3) printf("Case %d: Tie\n",tc);
		else if(N&1) printf("Case %d: CodeForces\n",tc);
		else printf("Case %d: CodeMask\n",tc);
	}
	
	return 0;
}
