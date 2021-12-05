#include<iostream>

using namespace std;

int main()
{
	int n,c;
	int ans;
	
	while(cin>>n>>c)
	{
		int newword,oldword;
		
		ans=1;
		
		cin>>oldword;
		for(int l=1;l<n;l++)
		{
			cin>>newword;
			
			if(newword-oldword>c){
				ans=1;
			}
			else{
				ans++;
			}
			
			oldword=newword;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
