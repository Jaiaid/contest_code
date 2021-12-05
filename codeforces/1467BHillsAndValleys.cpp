#include <iostream>
#include <vector>

#define MAXLEN 300000

int main()
{
	int t;
	std::vector<int> a(MAXLEN);
	
	std::cin>>t;
	while(t>0)
	{
		int n;
		std::vector<int> hv_indx;
		
		std::cin>>n;
		for(int l=0;l<n;l++)
		{
			std::cin>>a[l];
		}
		
		int score=0;
		for(int l=2;l<n;l++)
		{	
			if(a[l-2]<a[l-1] && a[l-1]>a[l]){
				score++;
				hv_indx.push_back(l-1);
				//std::cout<<l-1<<' '<<std::endl;
			}
			else if(a[l-2]>a[l-1] && a[l-1]<a[l]){
				score++;
				hv_indx.push_back(l-1);
				//std::cout<<l-1<<' '<<std::endl;
			}
		}
		//std::cout<<"score "<<score<<std::endl;
		int max_score_reduce=0;
		for(unsigned int l=0;l<hv_indx.size();l++)
		{	
			int l1=hv_indx[l];
			int tmp_a=a[l1];
			int tmp_max_score_reduce=1;
			//std::cout<<l1<<' ';
			a[l1]=a[l1+1];
			if(l1+2<n && tmp_a>a[l1+1] && a[l1+1]<a[l1+2]){
				tmp_max_score_reduce++;
			}
			else if(l1+2<n && tmp_a<a[l1+1] && a[l1+1]>a[l1+2]){
				tmp_max_score_reduce++;
			}
			if(l1-1>0 && a[l1-2]<a[l1-1] && a[l1-1]>tmp_a && a[l1-1]<=a[l1]){
				tmp_max_score_reduce++;
			}
			else if(l1-1>0 && a[l1-2]>a[l1-1] && a[l1-1]<tmp_a && a[l1-1]>=a[l1]){
				tmp_max_score_reduce++;
			}
			//std::cout<<tmp_max_score_reduce<<' ';
			if(tmp_max_score_reduce>max_score_reduce){
				max_score_reduce=tmp_max_score_reduce;
			}
			
			tmp_max_score_reduce=1;
			a[l1]=a[l1-1];
			if(l1+2<n && tmp_a>a[l1+1] && a[l1+1]<a[l1+2] && a[l1+1]>=a[l1]){
				tmp_max_score_reduce++;
			}
			else if(l1+2<n && tmp_a<a[l1+1] && a[l1+1]>a[l1+2] && a[l1+1]<=a[l1]){
				tmp_max_score_reduce++;
			}
			if(l1-1>0 && a[l1-2]<a[l1-1] && a[l1-1]>tmp_a){
				tmp_max_score_reduce++;
			}
			else if(l1-1>0 && a[l1-2]>a[l1-1] && a[l1-1]<tmp_a){
				tmp_max_score_reduce++;
			}
			//std::cout<<tmp_max_score_reduce<<std::endl;
			if(tmp_max_score_reduce>max_score_reduce){
				max_score_reduce=tmp_max_score_reduce;
			}
			
			a[l1]=tmp_a;
			
			if(max_score_reduce==3){
				break;
			}
		}
		
		std::cout<<score-max_score_reduce<<std::endl;
		t--;
		hv_indx.clear();
	}
	
	return 0;
}
