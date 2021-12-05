#include <iostream>
#include <vector>
#include <algorithm>

#define MAXLEN 200000

int main()
{
	int t, n;
	std::vector<long long int> a(MAXLEN);

	std::cin >> t;
	while(t)
	{
		std::cin >> n;
		n*=2;
		for(int i=0;i<n;i++)
		{
			std::cin>>a[i];
		}
		
		std::sort(a.begin(),a.begin()+n);		
		std::cout<<std::abs(a[n/2]-a[n/2-1])<<std::endl;
		t--;
	}
	
	return 0;
}
