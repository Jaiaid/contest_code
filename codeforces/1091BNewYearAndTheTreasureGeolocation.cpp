#include <iostream>

#define MAXLEN 1000

using namespace std;

int main()
{
	int n,x,y,a,b;
	long long int ansX,ansY;
	
	while(cin>>n)
	{
		ansX=0,ansY=0;
		
		for(int l=0;l<n;l++)
		{
			cin>>x>>y;
			ansX+=x;
			ansY+=y;
		}
		for(int l=0;l<n;l++)
		{
			cin>>a>>b;
			ansX+=a;
			ansY+=b;
		}
		
		ansX/=n, ansY/=n;
		
		cout<<ansX<<' '<<ansY<<endl;
	}
	
	return 0;
}
