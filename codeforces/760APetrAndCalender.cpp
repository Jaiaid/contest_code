#include<iostream>

using namespace std;

int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int n,m;
	int count;
	
	while(cin>>n>>m)
	{
		count=1;
		
		for(int l=1;l<months[n];l++)
		{
			m++;
			
			if(m>7){
				m=1;
				count++;
			}
		}
		
		cout<<count<<endl;
	}
	
	return 0;
}
