#include<iostream>

using namespace std;

int main()
{
	int n,m,z;
	int ans;
	
	while(cin>>n>>m>>z)
	{
		ans=0;
		for(int l=1;l<=z;l++)
		{
			if(l%n==0 && l%m==0) ans++;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
