#include <iostream>

#define MAXSEQUENCELEN 4000

using namespace std;

int GCD(int a, int b)
{
	while(a%b)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}

	return b;
}


int main()
{
	int n;
	int s[MAXSEQUENCELEN];
	int ansSize;

	while(cin>>n)
	{
		ansSize = 2*n-1;
		for(int l = 0;l < n;l++)
		{
			cin>>s[l];
		}

        int gcd = s[0];
		for(int l = 1;l < n;l++)
		{
			gcd = GCD(s[l], gcd);
		}

		if(gcd == s[0]) {
			cout<<ansSize<<endl;
			cout<<s[0];
			for(int l = 1;l < n;l++)
			{
				cout<<' '<<s[l]<<' '<<s[0];
			}
			cout<<endl;
		}
		else { 
			cout<<"-1"<<endl;
		}
	}

	return 0;
}
