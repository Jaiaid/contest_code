#include<iostream>

using namespace std;

int main()
{
	int n,L,barrier1[50],barrier2[50];
	
	while(cin>>n>>L)
	{
		for(int l=0;l<n;l++) cin>>barrier1[l];
		for(int l=0;l<n;l++) cin>>barrier2[l];

		int i;
		
		for(i=0;i<L;i++)
		{
			int l,l1;
			
			for(l=0;l<n;l++) 
			{
				for(l1=0;l1<n;l1++)
				{
					if(barrier1[l]==barrier2[l1]) break;
				}
				if(l1==n) break;
			}
			if(l==n) break;//if one entry of barrier1 is not found in barrier2

			for(l=0;l<n;l++) barrier2[l]=(barrier2[l]+1)%L;
		}
		
		if(i==L) cout<<"NO"<<endl;//if barrier2 can not be converted to barrier1 combination
		else cout<<"YES"<<endl;
	}

	return 0;
}
