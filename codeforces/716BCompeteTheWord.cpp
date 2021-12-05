#include<iostream>
#include<cstring>

#define MAXLEN 50000

using namespace std;

int main()
{
	char s[MAXLEN+1];
	
	while(cin>>s)
	{
		int lettercount[26],len;
		
		len=strlen(s);
		
		if(len<26){
			cout<<"-1"<<endl;
		}
		else{
			int tmp=len-26,l;
			
			for(l=0;l<26;l++)
			{
				lettercount[l]=0;
			}
			
			for(l=0;l<=tmp;l++)
			{	
				int l1;
				
				for(l1=0;l1<26;l1++)
				{
					if(s[l+l1]!='?'){
						lettercount[s[l+l1]-'A']++;
					}
				}
				
				for(l1=0;l1<26;l1++)
				{
					if(lettercount[l1]>1){
						break;
					}
				}
				
				if(l1==26){
					break;
				}
				
				for(l1=0;l1<26;l1++)
				{
					lettercount[l1]=0;
				}
			}
			
			if(l>tmp){
				cout<<"-1"<<endl;
			}
			else{
				for(int l1=0;l1<26;l1++)
				{
					if(s[l+l1]=='?'){
						for(int l2=0;l2<26;l2++)
						{
							if(lettercount[l2]==0){
								s[l+l1]=l2+'A';
								lettercount[l2]=1;
								break;
							}
						}
					}
				}
				
				for(l=0;s[l]!='\0';l++)
				{
					if(s[l]=='?'){
						s[l]='A';
					}
				}
				
				cout<<s<<endl;
			}
		}
	}
	
	return 0;
}
