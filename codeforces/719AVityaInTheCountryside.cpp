#include<iostream>

#define MAXDAY 92

using namespace std;

int main()
{
	int n,moon[MAXDAY];
	
	while(cin>>n)
	{
		for(int l=0;l<n;l++)
		{
			cin>>moon[l];
		}
		if(n==1){
			if(moon[0]!=0 && moon[0]!=15){
				cout<<"-1"<<endl;
			}
			else if(moon[0]==15){
				cout<<"DOWN"<<endl;
			}
			else{
				cout<<"UP"<<endl;
			}
		}
		else if((moon[n-1]>moon[n-2] && moon[n-1]<15) || moon[n-1]==0){
			cout<<"UP"<<endl;
		}
		else{
			cout<<"DOWN"<<endl;
		}
	}
	
	return 0;
}
