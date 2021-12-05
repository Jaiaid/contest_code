#include <iostream>
#include <string>

int main()
{
	unsigned long long int k;
	const std::string temp_str = "codeforces";
	
	while(std::cin>>k)
	{
		unsigned long long int char_counter[10]={1,1,1,1,1,1,1,1,1,1};
		unsigned long long int tmp=1;
		int l=0;
		while(tmp<k)
		{
			l%=10;
			char_counter[l]++;
			tmp=1;
			for(int l1=0;l1<10;l1++)
			{
				tmp*=char_counter[l1];
			}
			l++;
		}
		
		for(unsigned int l=0;l<temp_str.size();l++)
		{
			std::cout<<std::string(char_counter[l],temp_str[l]);
		}
		std::cout<<std::endl;
	}
	
	return 0;
}
