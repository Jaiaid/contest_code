#include<iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	
	while(cin>>a>>b>>c>>d)
	{
		int i;
		if(b < d) {
			int tmp;
			tmp = b, b = d, d = tmp;
			tmp = c, c = a, a = tmp;
		}
		for(i = 0;i <= c && (b + a*i -d)%c != 0;i++);
		
		if(i > c) cout<<"-1"<<endl;
		else cout<<b+a*i<<endl;
	}
	
	return 0;
}
