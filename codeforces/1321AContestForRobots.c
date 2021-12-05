#include <stdio.h>

int main()
{
	int n;
	int r[100], b[100];
	int i, r_exclusive_win_count, b_exclusive_win_count;
	
	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%d", &r[i]);
	}
	for(i = 0;i < n;i++)
	{
		scanf("%d", &b[i]);
	}
	
	r_exclusive_win_count = 0;
	b_exclusive_win_count = 0;
	for(i = 0;i < n;i++)
	{
		if (r[i] == 1 && b[i] == 0) {
			r_exclusive_win_count++;
		}
		else if (r[i] == 0 && b[i] == 1) {
			b_exclusive_win_count++;
		}
	}
	
	if (r_exclusive_win_count == 0) {
		printf("-1\n");
	}
	else if (r_exclusive_win_count > b_exclusive_win_count) {
		printf("1\n");
	}
	else {
		int ans = 1 + (b_exclusive_win_count - r_exclusive_win_count) / r_exclusive_win_count + 1;
		printf("%d\n", ans);
	}
	
	return 0;
}
