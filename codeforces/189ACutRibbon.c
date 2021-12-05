#include <stdio.h>

#define MAXLEN 40000

int dp[MAXLEN+1];

int main()
{
	int n, validPiece[3];
	int len, l;

	while(scanf("%d%d%d%d", &n, &validPiece[0], &validPiece[1], &validPiece[2])==4)
	{
		for(l = 0;l <= n;l++) dp[l] = 0;

		dp[validPiece[0]] = 1, dp[validPiece[1]] = 1, dp[validPiece[2]] = 1;

		for(len = 1;len <= n;len++)
		{
			for(l = 0;l < 3;l++)
			{
				if(len-validPiece[l] > 0 && dp[len-validPiece[l]]) {
					dp[len] = (dp[len] > dp[len-validPiece[l]]+1)?dp[len]:dp[len-validPiece[l]]+1;
				}
			}
			//printf("%d\n",dp[len]);
		}

		printf("%d\n", dp[n]);
	}

	return 0;
}
