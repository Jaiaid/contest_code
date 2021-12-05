#include <iostream>
#include <vector>

#define MAXCUBE 3

using namespace std;


class numberGenerator
{
	int n;
	int cube[MAXCUBE][6];
public:
	
	void init()
	{
		cin>>n;
		for(int l = 0;l < n;l++)
		{
			for(int l1 = 0;l1 < 6;l1++)
			{
				cin>>cube[l][l1];
			}
		}
	}
	
	bool canGenerate(int number)
	{
		int digit[MAXCUBE], digitCount = 0;
		while(number)
		{
			digit[digitCount] = number%10;
			number/=10;
			digitCount++;
		}
		
		for(int start = 0;start < n;start++)
		{
			int madeDigit = 0;
			//cout<<"start: "<<start<<endl;
			for(int indx = start, attempt = 0;attempt < n;indx++,attempt++)
			{
				indx%=n;
				for(int l = 0;l < 6;l++)
				{
					if(cube[indx][l]==digit[madeDigit]) {
						madeDigit++;
						break;
					}
					//cout<<indx<<' '<<l<<endl;
				}
			}
			//cout<<"madeDigit: "<<madeDigit<<endl;
			if(madeDigit == digitCount) return true;
		}
		
		return false;
	}
};

int main()
{
	numberGenerator helper;
	int ans = 0;

	helper.init();
	for(int l = 1;helper.canGenerate(l);l++) ans++;
	
	cout<<ans<<endl;
	
	return 0;
}
