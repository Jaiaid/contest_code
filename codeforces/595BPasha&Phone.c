#include<stdio.h>

#define MOD 1000000007

int aseq[100000],bseq[100000];

long long int portion_count(int len,int indx)
{
	int l;
	double pow,tmp;
	long long int ans=0;
	
	for(pow=1,l=1;l<len;l++) pow*=10;
	
	tmp=pow*10/aseq[indx];
	if(tmp>(long long int)tmp) tmp=(long long int)tmp+1;
	ans+=tmp;
	tmp=pow*(bseq[indx]+1)/aseq[indx];
	if(tmp>(long long int)tmp) tmp=(long long int)tmp+1;
	ans-=tmp;
	tmp=pow*bseq[indx]/aseq[indx];
	if(tmp>(long long int)tmp) tmp=(long long int)tmp+1;
	ans+=tmp;
	
	return ans%MOD;
}

int main()
{
	int n,k;
	int l,tmp;
	long long int ans;
	
	while(2==scanf("%d%d",&n,&k))
	{
		tmp=n/k;
		
		for(l=1;l<=tmp;l++) scanf("%d",&aseq[l]);
		for(l=1;l<=tmp;l++) scanf("%d",&bseq[l]);
		
		for(ans=1,l=1;l<=tmp;l++)
		{
			ans*=portion_count(k,l);
			if(ans>MOD) ans%=MOD;
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}


