#include<iostream>
#include<algorithm>

#define MAX_CITY 200000
#define MAX_DIFF 2000000001

using namespace std;

int main()
{
	int n;
	long long int pos[MAX_CITY];
	int minimalDiffCount;
	long long int minDiff;
	
	while(cin>>n)
	{
		minimalDiffCount = 0;
		minDiff = MAX_DIFF;

		for(int l = 0;l < n;l++)
		{
			long long int tmp;
			cin>>tmp;
			pos[l] = tmp;
		}
		
		sort(&pos[0], &pos[0]+n);

		for(int l = 1;l < n;l++)
		{
			long long int diff = abs(pos[l]-pos[l-1]);
			if(diff < minDiff) minDiff = diff;
		}
		
		for(int l = 1;l < n;l++)
		{
			long long int diff = abs(pos[l]-pos[l-1]);
			if(diff == minDiff) minimalDiffCount++;
		}
		
		cout<<minDiff<<' '<<minimalDiffCount<<endl;
	}
	
	return 0;
}
