#include <iostream>

#define MAXLEN 16

using namespace std;

int main()
{
	char s[MAXLEN];

	while(cin>>s)
	{
		int len = 0;
		int neededChange = 0;
		for(len = 0;s[len] != '\0';len++);

		if(len == 1) neededChange = 1;
		else {
			for(int l = 0, l1 = len - 1;l < l1;l++, l1--)
			{
				if(s[l] != s[l1]) neededChange++;
			}
		}

		if(neededChange == 1) cout<<"YES"<<endl;
		else if(neededChange == 0 && len%2 == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
