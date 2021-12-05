#include <stdio.h>

int main()
{
	int x,y,z;
	int certain_vote;
	char result;
	
	while(3==scanf("%d%d%d",&x,&y,&z))
	{
		certain_vote=x-y;
		
		if(certain_vote>0) result='+';
		else if(certain_vote<0) result='-';
		else result='0';
		
		if(result=='+' && z>=certain_vote) result='?';
		else if(result=='-' && z>=-certain_vote) result='?';
		else if(result=='0' && z>0) result='?';
		
		printf("%c\n",result);
	}
	
	return 0;
}
