#include<iostream>

using namespace std;

int main()
{
	int n,ara[200001];

	while(cin>>n)
	{
		for(int l=1;l<=n;l++) cin>>ara[l];
		
		for(int i=1;i<=n-i+1;i++)
		{
			if(i%2!=0){
				int tmp=ara[i];
				ara[i]=ara[n-i+1];
				ara[n-i+1]=tmp;
			}
		}
		
		cout<<ara[1];
		for(int l=2;l<=n;l++)
		{
			cout<<' '<<ara[l];
		}
		cout<<endl;
	}

	return 0;
}
