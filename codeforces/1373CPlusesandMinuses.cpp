#include <iostream>
#include <string>
#include <vector>

int main()
{
	int t;
	std::string s;
	unsigned long long int ans=0;
	
	std::cin>>t;
	while(t>0)
	{
		std::cin>>s;
		
		std::vector<int> minus_plus_sum(s.size(), 0);
		for(int l=0,tmp=0;l<(int)s.size();l++)
		{
			if(s[l]=='-') tmp--;
			else tmp++;
			
			minus_plus_sum[l]=tmp;
		}
		
		ans=0;
		for(int l=0,mark=0;l<(int)s.size();l++)
		{
			if(minus_plus_sum[l]+mark<0){
				mark++;
				ans+=l+1;
			}
			if(l+1==(int)s.size()){
				ans+=l+1;
			}
		}
		
		std::cout<<ans<<std::endl;
		
		t--;
	}
	
	return 0;
}
