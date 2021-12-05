#include <iostream>

#define MAXCHILD 100

using namespace std;

int main()
{
	int n, m, aral[MAXCHILD];
	int count[MAXCHILD + 1], to[MAXCHILD + 1];
	int a[MAXCHILD + 1];


	while(cin>>n>>m)
	{
		bool validSeq = true;
		for(int l = 0;l < m;l++) cin>>aral[l];
		for(int l = 1;l <= n;l++) count[l] = 0, a[l] = 0, to[l] = 0;

		for(int l = 1;l < m;l++)
		{
			if(aral[l] - aral[l - 1] > 0) {
				a[aral[l - 1]] = aral[l] - aral[l - 1];
			}
			else {
				a[aral[l - 1]] = n + aral[l] - aral[l - 1];
			}

			if(to[aral[l - 1]] == 0) {
				to[aral[l - 1]] = aral[l];
			}
			else if(to[aral[l - 1]] != aral[l]) {
				validSeq = false;
				break;
			}

			count[a[aral[l - 1]]] = 1;
		}

		if(!validSeq) {
			cout<<"-1\n";
			continue;
		}

		for(int l = 1, l1 = 1;l <= n;l++)
		{
			if(count[l] == 0) {
				while(l1 <= n && a[l1] != 0) l1++;
				if(l1 <= n) {
					a[l1] = l;
					count[l] = 1;
				}
			}
		}

		int l = 1;
		while(l <= n)
		{
			if(count[l] != 1) break;
			l++;
		}

		if(l > n) {
			for(l = 1;l <= n;l++)
			{
				cout<<a[l]<<' ';
			}
			cout<<endl;
		}
		else {
			cout<<"-1\n";
		}
	}

	return 0;
}
