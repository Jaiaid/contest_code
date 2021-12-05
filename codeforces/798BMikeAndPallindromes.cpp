#include <iostream>
#include <cstring>

#define INF 3000
#define MAXSTR 50
#define MAXLEN 51

using namespace std;

int moveToMakeSame(char s1[], char s2[])
{
	char s[2*MAXLEN];
	int len = strlen(s2);
	int move = INF;

	for(int l = 0;l < 2*MAXLEN;l++) s[l] = s2[l%len];

	for(int l = 0;l < len;l++)
	{
		if(s1[0] == s2[l]) {
			bool equal = true;
			for(int l1 = 0, l2 = l;s1[l1];l1++, l2++)
			{
				if(s1[l1] != s[l2]) {
					equal = false;
					break;
				}
			}

			if(equal) {
				move = l;
				break;
			}
		}
	}

	return move;
}

int main()
{
	char str[MAXSTR][MAXLEN];
	int n;
	int minMove;

	while(cin>>n)
	{
		for(int l = 0;l < n;l++) cin>>str[l];

		minMove = INF;
		for(int l = 0;l < n;l++)
		{
			int move = 0;
			for(int l1 = 0;l1 < n;l1++)
			{
				if(l == l1) continue;
				else move += moveToMakeSame(str[l], str[l1]);
			}

			if(minMove > move) minMove = move;
		}

		if(minMove < INF) cout<<minMove<<endl;
		else cout<<"-1"<<endl;
	}

	return 0;
}
