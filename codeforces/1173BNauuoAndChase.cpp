#include <iostream>
#include <vector>

#define MAXPIECES 1001

using namespace std;

int main()
{
	int n;
	int m;
	vector<int> x(MAXPIECES,0),y(MAXPIECES,0);
	
	while(cin>>n)
	{
		m=0;
		int r=0,c=0;
		for(int l=1;l<=n;l++)
		{
			if(r==c){
				r++;
				if(c==0) c++;
			}
			else c++;
			
			x[l]=r,y[l]=c;
			if(r>m || c>m) m++;
		}
		
		
		cout<<m<<endl;
		for(int l=1;l<=n;l++)
		{
			cout<<x[l]<<' '<<y[l]<<endl;
		}
	}
	
	return 0;
}
