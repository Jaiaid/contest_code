#include <iostream>
#include <string>

#define MAXLEN 100

int main()
{
	int t;
	std::string s(MAXLEN, '\0');
	
	std::cin>>t;
	while(t>0)
	{
		std::cin>>s;
		
		int one_count=0,zero_count=0;
		for(unsigned int l=0;l<s.size();l++)
		{
			if(s[l]=='0') zero_count++;
			if(s[l]=='1') one_count++;
		}
		
		int min_count=(zero_count<one_count)?zero_count:one_count;
		if(min_count%2==0){
			std::cout<<"NET"<<std::endl;
		}
		else{
			std::cout<<"DA"<<std::endl;
		}
		
		t--;
	}
	
	return 0;
}
