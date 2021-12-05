#include<iostream>

using namespace std;

int main()
{
	int n,m,k;
	int ans;
	
	while(cin>>n>>m>>k)
	{
		ans=1;
		m-=n;
		k=(k>n-k+1)?n-k+1:k;
		
		if(n==1){
			ans+=m;
		}
		else if(k==1){
			for(int sum=m,i=1;sum>0;sum-=i)
			{
				ans++;
				if(i<n) i++;
			}
		}
		else{
			if(m>0) ans++,m--;
			
			for(int sum=m,i=1;sum>0;)
			{
				if(i<k){
					i++;
					sum-=i*2-1;
					if(i==k) i=i*2-1;
				}
				else if(i<n){
					i++;
					sum-=i;
				}
				else sum-=i;
				
				if(sum>=0) ans++;
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
