#include <iostream>
#include <vector>

int main()
{
	int t, m, n;
	std::vector<int> a, p;
	
	std::cin>>t;
	for(;t;t--)
	{
		std::cin >> n >> m;
		
		a.clear();
		p.clear();
		for (int i = 0;i < n;i++)
		{
			int tmp;
			std::cin >> tmp;
			a.push_back(tmp);
		}
		for (int i = 0;i < m;i++)
		{
			int tmp;
			std::cin >> tmp;
			p.push_back(tmp);
		}
		
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (a[p[j]-1] > a[p[j]]) {
					int tmp = a[p[j]];
					a[p[j]] = a[p[j]-1];
					a[p[j]-1] = tmp;
				}
			}
		}
		
		bool is_sorted = true;
		for (int i = 1;i < n;i++)
		{
			if (a[i] < a[i-1]) {
				is_sorted = false;
				break;
			}
		}
		
		if (is_sorted) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
	
	return 0;
}
