#include<iostream>
#include<cstdlib>

#define MAXLEN 100000

using namespace std;

int main()
{
	char instruction[MAXLEN+1];
	int ans;
	
	while(cin>>instruction)
	{
		int ucount=0,dcount=0,lcount=0,rcount=0,l=0;
		
		for(l=0;instruction[l]!='\0';l++)
		{
			if(instruction[l]=='U'){
				ucount++;
			}
			else if(instruction[l]=='D'){
				dcount++;
			}
			else if(instruction[l]=='L'){
				lcount++;
			}
			else{
				rcount++;
			}
		}
		
		if(l%2==0){
			ans=(abs(ucount-dcount)+abs(lcount-rcount))/2;
		}
		else{
			ans=-1;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
