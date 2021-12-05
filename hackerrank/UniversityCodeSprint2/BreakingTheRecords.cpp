#include<iostream>

#define MAXGAME 1000

using namespace std;

int main()
{
	int n,s[MAXGAME];
	int besttimes,worsttimes;
	
	while(cin>>n)
	{
		besttimes=0,worsttimes=0;
		
		for(int l=0;l<n;l++) cin>>s[l];

		int max=s[0],min=s[0];
		
		for(int l=1;l<n;l++)
		{
			if(s[l]>max) besttimes++, max=s[l];
			else if(s[l]<min) worsttimes++, min=s[l];
		}
		
		cout<<besttimes<<' '<<worsttimes<<endl;
	}
	
	return 0;
}
