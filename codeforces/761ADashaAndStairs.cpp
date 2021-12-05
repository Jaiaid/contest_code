#include<iostream>

using namespace std;

int main()
{
	int a,b;
	
	while(cin>>a>>b)
	{
		if((a!=0 || b!=0) && (a==b || a==b-1 || b==a-1)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
