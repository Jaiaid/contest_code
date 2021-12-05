#include <stdio.h>

int main()
{
	char name[50];
	int T;
	int tc, wIndx[4];

	scanf("%d", &T);
	getchar();
	for(tc = 0;tc < T;tc++)
	{
		int l, flag = 1, wc = 1; 
		wIndx[wc] = 0;
		fgets(name, 50, stdin);

		for(l = 0, wc = 1;name[l];l++)
		{
			if(name[l] == ' ' && flag == 1) flag = 0;
			else if(flag == 0 && name[l] != ' ') {
				wc++;
				wIndx[wc] = l;
				flag = 1;
			}

			if('A' <= name[l] && name[l] <= 'Z') {
				name[l] = 'a' + name[l] - 'A';
			}
		}
		name[l - 1] = '\0'; 

		switch(wc)
		{
			case 3:
				name[0] = 'A' + name[0] - 'a';
				name[wIndx[2]] = 'A' + name[wIndx[2]] - 'a';
				printf("%c. %c. ", name[0], name[wIndx[2]]);
				break;
			case 2:
				name[0] = 'A' + name[0] - 'a';
				printf("%c. ", name[0]);
		}

		name[wIndx[wc]] = 'A' + name[wIndx[wc]] - 'a';
		printf("%s\n", &name[wIndx[wc]]);
	}

	return 0;
}
