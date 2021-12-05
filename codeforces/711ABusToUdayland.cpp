#include<iostream>

#define MAXROW 10000

using namespace std;

int main()
{
	char seats[MAXROW][6];
	int n;
	
	while(cin>>n)
	{
		int ansflag=0,row,col;
		
		for(int l=0;l<n;l++)
		{
			cin>>seats[l];
			
			if(seats[l][0]=='O' && seats[l][1]=='O'){
				row=l,col=0;
				ansflag=1;
			}
			else if(seats[l][3]=='O' && seats[l][4]=='O'){
				row=l,col=3;
				ansflag=1;
			}
		}
		
		if(ansflag){
			cout<<"YES"<<endl;
			seats[row][col]='+',seats[row][col+1]='+';
			for(int l=0;l<n;l++)
			{
				cout<<seats[l]<<endl;
			}
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
