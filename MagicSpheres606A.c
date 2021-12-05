#include<stdio.h>

int main()
{
	int a,b,c,x,y,z;
	
	while(6==scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z))
	{
		a-=x,b-=y,c-=z;
		while(a<0)
		{
			if(b>1){
				a++;
				b-=2;
			}
			else if(c>1){
				a++;
				c-=2;
			}
			else break;
		}
		while(b<0)
		{
			if(a>1){
				b++;
				a-=2;
			}
			else if(c>1){
				b++;
				c-=2;
			}
			else break;
		}
		while(c<0)
		{
			if(a>1){
				c++;
				a-=2;
			}
			else if(b>1){
				c++;
				b-=2;
			}
			else break;
		}
		
		if(a>=0 && b>=0 && c>=0) puts("Yes");
		else puts("No");
	}
	return 0;
}
