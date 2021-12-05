#include <stdio.h>

#define MAXLEN 100
#define FRIENDCOUNT 5

char names[FRIENDCOUNT][MAXLEN+1]={"Danil", "Olya", "Slava", "Ann", "Nikita"};

int stringCount(char *src, char *pattern)
{
	int count = 0;
	int l, l1;

	for(l = 0;src[l];l++)
	{
		if(src[l]!=pattern[0]) continue;
		for(l1 = 0;src[l+l1]==pattern[l1] && src[l+l1] && pattern[l1];l1++);
		if(pattern[l1] == '\0') count++;
	}

	return count;
}

int main()
{
	char str[MAXLEN+1];
	int l;
	int ans;

	while(scanf("%s",str)==1)
	{
		ans = 0;

		for(l = 0;l < FRIENDCOUNT;l++)
		{
			ans+=stringCount(str, names[l]);
		}

		if(ans==1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
