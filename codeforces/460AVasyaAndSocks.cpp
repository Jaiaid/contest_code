#include <iostream>

#define MAXSOCKS 100

using namespace std;


int main()
{
	int n, m;
	
	while(cin>>n>>m)
	{
		int remain = n, day = 0;
		do{
			day++;
			remain--;
			if(day%m == 0) remain++;
		}while(remain > 0);

		cout<<day<<endl;
	}

	return 0;
}
