#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	vector<int> ara;
	int x,y,z,maxenc;

	while(scanf(".%d.%d.%d",&x,&y,&z)==3)
	{
		ara.push_back(x+y+z);
	}

	for(int l=0;l<256;l++)
	{
		int key=ara[0]-l;
		
		printf("using key %d assuming first character is : %c(%d)\n\n",key,l,l);
		for(int l1=0;l1<ara.size();l1++)
		{
			putchar(ara[l1]-key);
		}
		puts("\n\n");
	}

	return 0;
}
