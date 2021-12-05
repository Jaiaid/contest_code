#include<iostream>

#define MAXHOUSE 100

using namespace std;

int main()
{
	int n, m, k;
	int price[MAXHOUSE];
	int ans;

	while(cin>>n>>m>>k)
	{
		for(int  l = 0;l < n;l++) cin>>price[l];

		ans = (n+1)*10;
		for(int l = 0;l < n;l++)
		{
			if(price[l] != 0 && price[l] <= k && abs((m-1)*10 - l*10) < ans) {
				ans = abs((m-1)*10 - l*10);
			}
		}

		cout<<ans<<endl;
	}
	
	return 0;
}
