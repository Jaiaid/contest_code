#include <iostream>

using namespace std;

int main()
{
	long long int n, k;
	long long int diploma, certificate;

	while(cin>>n>>k)
	{
		k++;
		diploma = (n/2)/k;
		certificate = diploma*(k - 1);

		cout<<diploma<<' '<<certificate<<' '<<n - (diploma + certificate)<<endl;
	}

	return 0;
}
