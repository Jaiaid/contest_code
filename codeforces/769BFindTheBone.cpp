#include <iostream>
#include <cstdio>
#include <algorithm>
 
#define MAXHOLE 2000001

using namespace std;

bool bin_search(int ara[], int size, int el)
{
	int lindx = 0, rindx = size-1, mindx = (size/2);

	while(lindx <= rindx && ara[mindx] != el)
	{
		if(el < ara[mindx]) {
			rindx = mindx - 1;
		}
		else {
			lindx = mindx + 1;
		}

		mindx = (lindx+rindx)/2;
	}

	if(lindx > rindx) return false;
	return true;
}

int main()
{
	int n, m, k;
	int holes[MAXHOLE];
	
	while(cin>>n>>m>>k)
	{
		int bonecup = 1;
		bool noeffect = false;
		int swapcup1, swapcup2;

		for(int l = 0;l < m;l++) scanf("%d", &holes[l]);
		sort(&holes[0], &holes[0]+m);

		if(holes[0] == 1) noeffect = true;
		for(int l = 0;l < k;l++)
		{
			scanf("%d%d", &swapcup1, &swapcup2);

			if(!noeffect) {
				if(swapcup1 == bonecup) bonecup = swapcup2;
				else if(swapcup2 == bonecup) bonecup = swapcup1;

				if(bin_search(holes, m, bonecup)) noeffect = true;
			}
		}
		cout<<bonecup<<endl;
	}

	return 0;
}
