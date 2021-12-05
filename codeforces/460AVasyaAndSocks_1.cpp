#include <iostream>

#define MAXSOCKS 100

using namespace std;


int days(int n, int m)
{
	if(n < m) return n;
	return (n/m)*m+days(n%m+n/m, m);
}

int main()
{
	int n, m;
	
	while(cin>>n>>m)
	{
		cout<<days(n, m)<<endl;
	}

	return 0;
}
