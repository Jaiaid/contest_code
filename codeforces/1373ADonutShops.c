#include <stdio.h>

int main()
{
	int t;
	unsigned long long int a,b,c;
	
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%llu%llu%llu",&a,&b,&c);
		
		if(c<=a){
			printf("-1");
		}
		else{
			printf("1");
		}
		
		if(a*b<=c){
			printf(" -1\n");
		}
		else{
			printf(" %llu\n",b);
		}
		
		t--;
	}
	
	return 0;
}
