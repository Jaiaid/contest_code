#include <iostream>

#define MAXLEN 100

using namespace std;

void bubble_sort(int *ara,int n)
{
	for(int l=0;l<n;l++)
	{
		int k=n-l;
		for(int l1=1;l1<k;l1++)
		{
			if(ara[l1-1]>ara[l1]) {
				int tmp=ara[l1-1];
				ara[l1-1]=ara[l1];
				ara[l1]=tmp; 
			}
		}
	}
	
	return;
}

int main()
{
	int n,a[MAXLEN];
	int ans;
	
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
	
		ans=0;
		bubble_sort(a,n);
		for(int i=0;i<n;i+=2)
		{
			ans+=a[i+1]-a[i];
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
