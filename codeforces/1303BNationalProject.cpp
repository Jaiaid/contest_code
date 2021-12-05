#include <iostream>

int main()
{
	long long int t,n,g,b;
	long long int ans;
	
	std::cin>>t;
	for(;t;t--)
	{
		std::cin>>n>>g>>b;

		long long int n_half=(n%2==0)?n/2:n/2+1;
		long long int other_half=n-n_half;
		
		ans=(n_half/g)*(g+b)+(n_half%g);
		long long int unused_day=ans-n_half;
		if(other_half>=unused_day){ 
			ans+=other_half-unused_day;
		}
		else if(n_half%g==0){
			if(unused_day-other_half<b){
				ans-=unused_day-other_half;
			}
			else if(unused_day-other_half>=b){
				ans-=b;
			}
		}
		
		std::cout<<ans<<std::endl;
	}
	
	return 0;
}
