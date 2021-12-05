#include<stdio.h>

int main(){
	int n,q,l,l1;
	long long int ara[100000];
	long long int t,ai;
	scanf("%d%d",&n,&q);
	scanf("%lld",&ai);

	ara[0]=ai;
    for(l=1;l<n;l++)
    {
        scanf("%lld",&ai);
        ara[l]=ai+ara[l-1];
    }

    for(l=0;l<q;l++)
    {
        scanf("%lld",&t);
        t%=ara[n-1];
        for(l1=0;ara[l1]<=t;l1++);
        printf("%d\n",l1+1);
    }
	return 0;
}
