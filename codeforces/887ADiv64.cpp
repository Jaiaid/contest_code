#include <iostream>
#include <cstring>

#define MAXLEN 100

using namespace std;

int main()
{
	char binaryNum[MAXLEN+1];
	
	while(cin>>binaryNum)
	{
		int zeroCount = 0, hasOne = 0;
		for(int l = strlen(binaryNum)-1;l >= 0;l--)
		{
			if(binaryNum[l] == '0') zeroCount++;
			if(zeroCount >= 6 && binaryNum[l] == '1') {
				hasOne = 1;
				break;
			}
		}
		
		if(zeroCount >= 6 && hasOne) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}

	return 0;
}
