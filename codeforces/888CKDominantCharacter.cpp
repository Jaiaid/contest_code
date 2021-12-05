#include <iostream>

#define INF 100001
#define MAX_STRLEN 100000
#define NUM_CHAR 26

using namespace std;

int main()
{
	char s[MAX_STRLEN+1];
	int maxDistanceBetweenOccurance[NUM_CHAR], lastOccurance[NUM_CHAR];
	int minK;

	while(cin>>s)
	{
		int len = 0;

		for(int l = 0;l < NUM_CHAR;l++)
		{
			maxDistanceBetweenOccurance[l] = 0;
			lastOccurance[l] = -1;
		}

		for(int l = 0;s[l] != '\0';l++, len++)
		{
			int indx = s[l]-'a';
			int tmp = l-lastOccurance[indx];
			
			if(tmp > maxDistanceBetweenOccurance[indx]) {
				maxDistanceBetweenOccurance[indx] = tmp;
			}

			lastOccurance[indx] = l; 
		}

		for(int indx = 0;indx < NUM_CHAR;indx++)
		{
			int tmp = len-lastOccurance[indx];
			
			if(tmp > maxDistanceBetweenOccurance[indx]) {
				maxDistanceBetweenOccurance[indx] = tmp;
			} 
		}

		minK = INF;
		for(int l = 0;l < NUM_CHAR;l++)
		{
			if(lastOccurance[l] != -1 && maxDistanceBetweenOccurance[l] < minK) {
				minK = maxDistanceBetweenOccurance[l];
			}
		}

		cout<<minK<<endl;
	}

	return 0;
}
