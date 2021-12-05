#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int n;
	double xv,yv,xi,yi,vi;
	double min_time_sqr;
	
	while(cin>>xv>>yv>>n)
	{
		double dist_sqr;
		min_time_sqr=200*200+200*200;
		
		for(int l=0;l<n;l++)
		{
			cin>>xi>>yi>>vi;
		
			dist_sqr=(xi-xv)*(xi-xv)+(yi-yv)*(yi-yv);
			
			if(dist_sqr/(vi*vi)<min_time_sqr){
				min_time_sqr=dist_sqr/(vi*vi);
			}
		}
		
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<sqrt(min_time_sqr)<<endl;
	}
	
	return 0;
}
