#define MAXSHOP 100000

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_range_search(int *ara,int len,int ul);

int main()
{
	int n,q,x[MAXSHOP],m;
	int ans;
	
	while(cin>>n)
	{
		for(int l=0;l<n;l++)
		{
			cin>>x[l];
		}
		
		sort(&x[0],&x[0]+n);
		
		cin>>q;
		for(int l=0;l<q;l++)
		{
			cin>>m;

			if((ans=binary_range_search(x,n,m))==-1){
				cout<<"0"<<endl;
			}
			else{
				cout<<ans<<endl;
			}
		}
	}
}

int binary_range_search(int *ara,int len,int ul)
{
	int lindex=0,uindex=len,midindex=len/2;
	
	if(ul<ara[0]) return 0;
	else if(ul>=ara[len-1]) return len;
	
	while(ul<ara[lindex-1] || ul>=ara[lindex])
	{
		if(ara[midindex]<=ul){
			lindex=midindex+1;
		}
		else{
			uindex=midindex-1;
		}
		
		midindex=(uindex+lindex)/2;
	}
	
	return lindex;
}
