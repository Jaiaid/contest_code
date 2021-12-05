#include <iostream>

#define MAXLEN 100

using namespace std;

int main()
{
	int n, k;
	int ryhmeCount[MAXLEN];
	int children[MAXLEN];
	
	while(cin>>n>>k)
	{
		for(int l = 0;l < k;l++) cin>>ryhmeCount[l];
		for(int l = 0;l < n;l++) children[l] = l+1;
		
		int leader = 0, removeIdx = 0;
		for(int l = 0;l < k;l++)
		{
			removeIdx = leader%n;
			for(int l1 = 1;l1 <= ryhmeCount[l];removeIdx++, l1++);
			removeIdx %= n;
			
			cout<<children[removeIdx]<<' ';
			for(int l1 = removeIdx+1;l1 < n;l1++)
			{
				children[l1-1] = children[l1];
			}
			n--;
			leader = removeIdx%n;
		}
		cout<<endl;
	}

	return 0;
}
