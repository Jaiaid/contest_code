#include<iostream>

#define MAXCOL 100

using namespace std;

int main()
{
	char pixel;
	int n,m;
	
	while(cin>>n>>m)
	{
		int ans=0;
		
		for(int l=0;l<n;l++)
		{
			for(int l1=0;l1<m;l1++)
			{
				cin>>pixel;
				if(pixel!='B' && pixel!='W' && pixel!='G'){
					ans=1;
				}
			}
		}
		
		if(ans){
			cout<<"#Color"<<endl;
		}
		else{
			cout<<"#Black&White"<<endl;
		}
	}
	
	return 0;
}
