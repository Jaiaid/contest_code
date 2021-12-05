#include <iostream>
#include <algorithm>

#define MAXSEQLEN 100000
#define POS_INF 100001
#define NEG_INF -100001

using namespace std;

int main()
{
	int n, a[MAXSEQLEN];

	while(cin>>n)
	{
		for(int l = 0;l < n;l++) cin>>a[l];
		sort(a, a+n);

		int ans = 0, indx;
		for(indx = n-1;indx >= 0 && a[indx] > 0 ;ans += a[indx], indx--);

		if(ans%2 == 1) {
			cout<<ans<<endl;
		}
		else {
			int minPosOdd = POS_INF, maxNegOdd = NEG_INF;
			for(int l = indx+1;l < n;l++)
			{
				if(a[l]%2 == 1) {
					minPosOdd = a[l];
					break;
				}
			}

			for(int l = indx;l >= 0;l--)
			{
				if((-a[l])%2 == 1) {
					maxNegOdd = a[l];
					break;
				}
			}

			if(minPosOdd < -maxNegOdd) ans -= minPosOdd;
			else ans += maxNegOdd;

			cout<<ans<<endl;
		}	
	}

	return 0;
}
