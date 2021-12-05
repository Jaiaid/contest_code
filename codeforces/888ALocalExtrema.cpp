#include <iostream>

#define MAXPOINT 1000

using namespace std;

int main()
{
	int n, a[MAXPOINT];
	int localExtremum;
	
	while(cin>>n)
	{
		for(int l = 0;l < n;l++) cin>>a[l];
		
		n--;
		localExtremum = 0;
		for(int l = 1;l < n;l++)
		{
			if((a[l-1]>a[l] && a[l]<a[l+1]) || (a[l-1]<a[l] && a[l]>a[l+1])) {
				localExtremum++;
			}
		}
		
		cout<<localExtremum<<endl;
	}

	return 0;
}
