#include <iostream>
#include <vector>

#define MAXLEN 300000

int main()
{
	int t, n;
	std::vector<int> a(MAXLEN);
	
	std::cin >> t;
	while(t)
	{
		std::cin >> n;
		for(int i=0;i<n;i++)
		{
			std::cin >> a[i];
		}
		
		int i;
		for(i=0;i<n;i++)
		{
			if(a[i] < i && a[i] < n-i-1){
				break;
			}
			if(i<n-1 && a[i]==a[i+1]){
				if(a[i]>i || a[i]>n-i-1){
					a[i]--;
				}
				else{
					a[i+1]--;
				}
			}
		}
		
		if(i==n) {
			std::cout<<"Yes"<<std::endl;
		}
		else {
			std::cout<<"No"<<std::endl;
		}
		t--;
	}
	
	return 0;
}
