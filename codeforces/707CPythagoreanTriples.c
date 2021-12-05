#include<stdio.h>

int main()
{
	unsigned long long int n;
	unsigned long long int tmp;
	
	while(1==scanf("%llu",&n))
	{
		if(n<=2){
			puts("-1");
		}
		else if(n%2){
			tmp=n*n;
			printf("%llu %llu\n",(n*n+1)/2,(n*n-1)/2);
		}
		else{
			tmp=(n*n)/2;
			printf("%llu %llu\n",((n*n)/2+2)/2,((n*n)/2-2)/2);
		}
	}
	return 0;
}
