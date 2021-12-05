#include<iostream>

#define MAXSIZE 100

using namespace std;

int main()
{
	int n,ara[MAXSIZE];
	int numarray,ri[MAXSIZE];
	
	while(cin>>n)
	{
		for(int l=0;l<n;l++)
		{
			cin>>ara[l];
		}
		
		numarray=0;
		int indx=0,sum=ara[0];
		for(int l=1;l<n;l++)
		{
			sum+=ara[l];
			
			if(sum==0 && sum-ara[l]!=0){
				ri[indx]=l;
				indx++;
				numarray++;
				sum=ara[l];
			}
		}
		if(sum!=0){
			ri[indx]=n;
			indx++;
			numarray++;
		}
		
		if(numarray==0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			cout<<numarray<<endl;
			cout<<"1 "<<ri[0]<<endl;
			
			for(int l=1;l<indx;l++)
			{
				cout<<ri[l-1]+1<<' '<<ri[l]<<endl;
			}
		}
	}
	
	return 0;
}
