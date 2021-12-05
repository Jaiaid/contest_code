#include <stdio.h>

#define MAXCHILDREN 5000
#define CHILDTYPE 3
#define MAXTEAM MAXCHILDREN/CHILDTYPE

int main()
{
	int n, children[MAXCHILDREN];
	int l, l1, typeIndices[CHILDTYPE][MAXCHILDREN], typeCount[CHILDTYPE];
	int teamCount;

	while(scanf("%d", &n)==1)
	{
		for(l = 0;l < n;l++) scanf("%d", &children[l]);

		teamCount = 0;
		for(l = 0;l < CHILDTYPE;l++) typeCount[l] = 0;

		for(l = 0;l < n;l++)
		{
			typeIndices[children[l]-1][typeCount[children[l]-1]] = l+1;
			typeCount[children[l]-1]++;
		}

		for(l = 1, teamCount = typeCount[0];l < CHILDTYPE;l++)
		{
			if(teamCount > typeCount[l]) teamCount = typeCount[l];
		}

		printf("%d\n", teamCount);
		if(teamCount > 0) {
			for(l = 0;l < teamCount;l++)
			{
				for(l1 = 0;l1 < CHILDTYPE;l1++)
				{
					printf("%d ", typeIndices[l1][l]);
				}
				putchar('\n');
			}
		}
	}

	return 0;
}
