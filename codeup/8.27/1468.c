#include <stdio.h>
int main(void)
{
	int n, i, j, arr[101][101];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			arr[i][j] = n * (i - 1) + j;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (j = 1; j <= n; j++)
			{
				printf("%d ", arr[i][j]);
			}
		}
		else
		{
			for (j = n; j >= 1; j--)
			{
				printf("%d ", arr[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
