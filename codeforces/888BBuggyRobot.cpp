#include <iostream>

#define MAXMOVE 100
#define MIN(a,b) (a<b?a:b)

using namespace std;

int main()
{
	char moveSeq[MAXMOVE+1];
	int n;
	int maxCorrectMove;

	while(cin>>n)
	{
		int moveTypeCount[4] = {0, 0, 0, 0};
		
		cin>>moveSeq;
		
		maxCorrectMove = 0;
		
		for(int l = 0;l < n;l++)
		{
			switch(moveSeq[l])
			{
				case 'L':
					moveTypeCount[0]++;
					break;
				case 'R':
					moveTypeCount[1]++;
					break;
				case 'U':
					moveTypeCount[2]++;
					break;
				case 'D':
					moveTypeCount[3]++;
			}
		}
		
		maxCorrectMove = MIN(moveTypeCount[0], moveTypeCount[1])*2+MIN(moveTypeCount[3], moveTypeCount[2])*2;
		cout<<maxCorrectMove<<endl;
	}
	
	return 0;
}
