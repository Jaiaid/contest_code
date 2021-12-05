#include<iostream>

using namespace std;

int main()
{
	int n;
	long long int ai,ai_1;

	while(cin>>n)
	{
		cin>>ai;
		for(int l=1;l<n;l++)
		{
			cin>>ai_1;
			cout<<ai+ai_1<<' ';
			ai=ai_1;
		}
		cout<<ai_1<<endl;
	}
	
	return 0;
}
