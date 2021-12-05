#include <iostream>
#include <cmath>

#define MAXHOUSE 100
#define MAXFACTOR 20

using namespace std;

int main()
{
	int n, k;

	while(cin>>n>>k)
	{
		int factorArray[MAXFACTOR], indx = 0, factor = 2;
		int tmpn = n;

		if(k == 1) {
			cout<<n<<endl;
			continue;
		}		
		for(factor = 2;factor < n && tmpn > 1;) 
		{
			if(tmpn%factor == 0) {
				factorArray[indx] = factor;
				indx++;
				tmpn /= factor;
			}
			else factor++;
		}

		if(indx < k) cout<<"-1"<<endl;
		else {
			int l;
			cout<<factorArray[0];
			for(l = 1;l < k-1;l++)
			{
				cout<<' '<<factorArray[l];
			}
			int m = 1;
			for(int l = k-1;l < indx;m *= factorArray[l], l++);
			cout<<' '<<m<<endl;
		}	
	}

	return 0;
}
