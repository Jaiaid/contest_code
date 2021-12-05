#include <iostream>
#include <vector>

#define MAXNOTE 10000

int main()
{
	int T,K;
	std::vector<int> noteset(MAXNOTE);
	
	std::cin>>T;
	for(int case_no=1;case_no<=T;case_no++)
	{
		std::cin>>K;
		for(int i=0;i<K;i++)
		{
			std::cin>>noteset[i];
		}
		
		int rule_break_count=0;
		for(int seq_sum=0,i=1;i<K;i++)
		{
			if(noteset[i]>noteset[i-1]){
				seq_sum++;
			}
			else if(noteset[i]<noteset[i-1]){
				seq_sum--;
			}
			
			if(seq_sum<-3 || 3<seq_sum){
				seq_sum=0;
				rule_break_count++;
			}
		}
		
		std::cout<<"Case #"<<case_no<<": "<<rule_break_count<<std::endl;
	}
	
	return 0;
}
