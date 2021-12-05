#include <iostream>

int main()
{
	long long int t,a[3],b[3];
	
	std::cin>>t;
	while(t>0)
	{
		std::cin>>a[0]>>a[1]>>a[2];
		std::cin>>b[0]>>b[1]>>b[2];
		
		int m_a[3] = {2,1,0};
		int m_b[3] = {1,0,2};
		long long int sum=0;
		for(int l=0,l1=0;l<3 && l1<3;)
		{	
			if(a[m_a[l]]>b[m_b[l1]]){
				if(m_a[l]>m_b[l1]){
					sum+=b[m_b[l1]]*m_a[l]*m_b[l1];
				}
				else if(m_a[l]<m_b[l1]){
					sum-=b[m_b[l1]]*m_a[l]*m_b[l1];
				}
				a[m_a[l]]-=b[m_b[l1]];
				b[m_b[l1]]=0;
				if(b[m_a[l]]>=a[m_a[l]]){
					b[m_a[l]]-=a[m_a[l]];
					a[m_a[l]]=0;
				}
				else{
					a[m_a[l]]-=b[m_a[l]];
					b[m_a[l]]=0;
				}
			}
			else{
				if(m_a[l]>m_b[l1]){
					sum+=a[m_a[l]]*m_a[l]*m_b[l1];
				}
				else if(m_a[l]<m_b[l1]){
					sum-=a[m_a[l]]*m_a[l]*m_b[l1];
				}
				b[m_b[l1]]-=a[m_a[l]];
				a[m_a[l]]=0;
				if(a[m_b[l1]]>=b[m_b[l1]]){
					a[m_b[l1]]-=b[m_b[l1]];
					b[m_b[l1]]=0;
				}
				else{
					b[m_b[l1]]-=a[m_b[l1]];
					a[m_b[l1]]=0;
				}
			}
			
			while(l<3 && a[m_a[l]]==0) l++;
			while(l1<3 && b[m_b[l1]]==0) l1++;
		}
		std::cout<<sum<<std::endl;
		t--;
	}
	
	return 0;
}
