#include <iostream>

#define MAXLEN 400

int main()
{
	int t,n;
	int a[MAXLEN];
	
	std::cin>>t;
	while(t>0)
	{
		std::cin>>n;
		for(int l=0;l<n;l++)
		{
			std::cin>>a[l];
		}
		
		int anomaly_pos_count=0;
		int odd_count = 0;
		int even_count = 0;
		for (int l=0;l<n;l++)
		{
			if(l%2!=a[l]%2){
				anomaly_pos_count++;
			}
			if(a[l]%2==0){
				even_count++;
			}
			else{
				odd_count++;
			}
		}
		
		if((n%2 && odd_count+1!=even_count) || (n%2==0 && odd_count!=even_count)){
			std::cout<<"-1"<<std::endl;
		}
		else{
			std::cout<<anomaly_pos_count/2<<std::endl;
		}
		
		t--;
	}
	
	return 0;
}
