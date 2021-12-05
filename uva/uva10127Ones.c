#include <stdio.h>

int modularPower(int base, int power, int div);

int main()
{
	int n;
	int digitCount;

	while(scanf("%d", &n) == 1)
	{
		int modSum = 0, term = 1, digitCount = 0;
		do
		{
			modSum=(modSum+term)%n;
			digitCount++;
			term=(term*10)%n;
		}while(modSum != 0);

		printf("%d\n", digitCount);
	}

	return 0;
}
