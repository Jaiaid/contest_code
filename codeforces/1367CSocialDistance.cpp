#include <iostream>
#include <string>

#define EMPTY '0'
#define FULL '1'

int main()
{
	int t,n,k;
	std::string s;
	int ans;
	
	std::cin>>t;
	while(t>0)
	{
		std::cin>>n>>k>>s;

		int right_empty_count=0, left_empty_count=0;
		ans=0;
		s=std::string(k,'0')+s+std::string(k,'0');
		for(unsigned int l=0;l<s.size();l++)
		{
			if(left_empty_count<k){
				if(s[l]==EMPTY){
					left_empty_count++;
				}
				else{
					left_empty_count=0;
				}
			}
			else if(left_empty_count==k){
				if(s[l]==FULL){
					left_empty_count=0;
				}
				else{
					left_empty_count++;
				}
			}
			else{
				if(s[l]==EMPTY){
					right_empty_count++;
					if(right_empty_count==k){
						right_empty_count=0;
						left_empty_count=k;
						ans++;
					}
				}
				else{
					left_empty_count=0;
					right_empty_count=0;
				}
			}
		}
		
		std::cout<<ans<<std::endl;
		
		t--;
	}

	return 0;
}
