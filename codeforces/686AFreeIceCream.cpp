#include<iostream>

using namespace std;

int main()
{
	int n;
	unsigned long long int x;
	char type[2];
	int tmp;
	int dchild;
	unsigned long long int rem;
	
	while((cin>>n>>x))
	{
		dchild=0;
		rem=x;
		
		for(int l=0;l<n;l++)
		{
			cin>>type>>tmp;
			
			if(type[0]=='+'){
				rem+=tmp;
			}
			else{
				if(rem>=tmp){
					rem-=tmp;
				}
				else{
					dchild++;
				}
			}
		}
		
		cout<<rem<<' '<<dchild<<endl;
	}

	return 0;
}
