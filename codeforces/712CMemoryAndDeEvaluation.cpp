#include<iostream>

using namespace std;

int main()
{
	int x,y;
	int ans;
	
	while(cin>>x>>y)
	{
		int triangle[3];
		triangle[0]=y,triangle[1]=y,triangle[2]=y,ans=0;
		
		while(triangle[0]!=x || triangle[1]!=x || triangle[2]!=x)
		{
			if(triangle[1]+triangle[2]-1>x){
				triangle[0]=x;
			}
			else{
				triangle[0]=triangle[1]+triangle[2]-1;
			}
			
			for(int l=1;l>=0;l--)
			{
				int tmp;
				
				if(triangle[l]>triangle[l+1]){
					tmp=triangle[l];
					triangle[l]=triangle[l+1];
					triangle[l+1]=tmp;
				}
			}
			
			ans++;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
