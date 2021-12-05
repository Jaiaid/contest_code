#include <stdio.h>

#define MAXLEN 3000

int main()
{
	char num[MAXLEN+1];
	int t, n;
	int i, sum;
	
	scanf("%d", &t);
	while(t)
	{
		scanf("%d", &n);
		scanf("%s", num);
		
		for(i=n-1;i>=0;i--)
		{
			if ((num[i]-'0')%2) {
				num[i+1]='\0';
				break;
			}
		}
		
		sum=1;
		if (i>=0) {
			sum=0;
			do {
				sum+=(num[i]-'0');
				i--;
			} while(i>=0 && sum%2);
		}
		
		if (sum%2) {
			printf("-1\n");
		}
		else {
			printf("%s\n", &num[i+1]);
		}
		t--;
	}
	
	return 0;
}
