#include<iostream>

using namespace std;

int main()
{
	int n,ara[101];
	
	while((cin>>n))
	{
		for(int l=1;l<=n;l++) cin>>ara[l];
		
		for(int l=1;l<=n;l++)
		{
			int tmp=n-l+1;
			for(int l1=2;l1<=tmp;l1++)
			{
				if(ara[l1]<ara[l1-1]){
					int tmp1=ara[l1-1];
					ara[l1-1]=ara[l1];
					ara[l1]=tmp1;
					cout<<l1-1<<' '<<l1<<endl;
				}
			}
		}
	}

	return 0;
}
