#include <iostream>

using namespace std;

int main()
{
	int n;

	while(cin>>n)
	{
		int ans;
		for(int l=1;;l++)
		{
			if(l*l>=n){
				ans = l+l;
				break;
			}
			else if(l*(l+1)>=n){
				ans = l+l+1;
				break;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
