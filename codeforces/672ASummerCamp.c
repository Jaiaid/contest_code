#include<stdio.h>

int main()
{
	int n;
	
	while(scanf("%d",&n)==1)
	{
		if(n<=9){
			printf("%d\n",n);
		}
		else if(n<=189){
			n-=10;
			printf("%d\n",(n%2)?((10+n/2)%10):((10+n/2)/10));
		}
		else{
			n-=190;
			if(n%3==0){
				printf("%d\n",(100+n/3)/100);
			}
			else if(n%3==1){
				printf("%d\n",((100+n/3)/10)%10);
			}
			else{
				printf("%d\n",(100+n/3)%10);
			}
		}
	}
	
	return 0;
}
