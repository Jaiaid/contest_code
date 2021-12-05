#include <stdio.h>

#define MAXLEN 100

int main()
{
	char s[MAXLEN+1];
	int t;
	int i,state,tmp_ans;
	int ans;
	
	scanf("%d", &t);
	while(t)
	{
		scanf("%s", s);
		state=0;
		ans=0;
		tmp_ans=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(state==0 && s[i]=='1'){
				state=1;
			}
			else if(state==1 && s[i]=='0'){
				state=2;
			}
			else if(state==2 && s[i]=='1'){
				state=1;
				ans+=tmp_ans;
				tmp_ans=0;
			}
			if(state==2){
				tmp_ans++;
			}
		}
		printf("%d\n",ans);
		t--;
	}
	
	return 0;
}
