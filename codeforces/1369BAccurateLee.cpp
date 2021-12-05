#include <iostream>
#include <string>

#define MAXLEN 100000

int main()
{
	int t,n;
	std::string s(MAXLEN, '\0');
	
	std::cin>>t;
	while(t>0)
	{
		std::cin>>n;
		std::cin>>s;
		
		// unsigned int type may fail in comparison with std::string::npos
		size_t first_one_idx = s.find_first_of("1");
		size_t last_zero_idx = s.find_last_of("0");
		
		// replace maximum  match with 1.*0 pattern with 0 
		if(first_one_idx!=std::string::npos && last_zero_idx!=std::string::npos 
		&& first_one_idx<last_zero_idx){
			s.replace(first_one_idx, last_zero_idx-first_one_idx+1, "0");
		}
		
		std::cout<<s<<std::endl;
		
		t--;
	}
	
	return 0;
}
