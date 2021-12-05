#include <iostream>

#define MAXLEN 100

using namespace std;

int main()
{
	char str[MAXLEN+1];
	int ans;

	while(cin>>str)
	{
		int len;
		int preQ[MAXLEN+1] = {0}, postQ[MAXLEN+1] = {0};
		
		ans = 0, len = 0;

		for(int l = 0, tmpCount = 0;str[l];l++, len++)
		{
			if(str[l] == 'Q') {
				tmpCount++;
			}
			else if(str[l] == 'A') {
				preQ[l] = tmpCount;
			}
		}

		for(int l = len-1, tmpCount = 0;l >= 0;l--)
		{
			if(str[l] == 'Q') {
				tmpCount++;
			}
			else if(str[l] == 'A') {
				postQ[l] = tmpCount;
			}
		}

		for(int l = 0;str[l];l++)
		{
			if(str[l] == 'A') {
				ans += preQ[l]*postQ[l];
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
