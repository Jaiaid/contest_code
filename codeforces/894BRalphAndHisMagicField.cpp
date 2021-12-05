#include <iostream>
#include <set>

#define MOD 1000000007

using namespace std;


unsigned long long int modPower(unsigned long long int base, unsigned long long int indx)
{
	if(indx == 0) return 1;

	unsigned long long int tmp = modPower((base*base)%MOD, indx/2)%MOD;

	if(indx%2 == 0) return tmp;
	
	return (base*tmp)%MOD; 
}

int main()
{
	int k;
	unsigned long long int n, m;
	unsigned long long int ans;

	while(cin>>n>>m>>k)
	{
		if(k != -1 || (n+m)%2 == 0) {
			ans = modPower(2, n-1 );
			ans = modPower(ans, m-1);
		}
		else ans = 0;

		cout<<ans<<endl;
	}
	return 0;
}
