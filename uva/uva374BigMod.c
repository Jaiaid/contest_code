#include <stdio.h>

int modularPower(int base, int power, int div);

int main()
{
	int B, P, M;

	while(scanf("%d%d%d", &B, &P, &M) == 3)
	{
		printf("%d\n", modularPower(B, P, M));
	}

	return 0;
}

int modularPower(int base, int power, int div)
{
	int tmpb = base%div;
	if(power == 0) return 1;
	/*
	 * initially it was if(power <= 1) return tmpb; which gives
	 * wrong answer in base>0 and power==0
	 */

	if(power&1) {
		return (tmpb*modularPower((tmpb*tmpb)%div, power>>1, div))%div;
	}

	return (modularPower((tmpb*tmpb)%div, power>>1, div))%div;
}
