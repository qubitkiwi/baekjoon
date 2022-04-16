#include <stdio.h>

int main(void)
{
	int N, K, i, end=0, max = 0, now=0;
	int f, r , x, g;
	int map[1000002] = {0, };

	f = 0;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &g, &x);
		map[x] = g;
		if (end < x) end = x;
	}

    // for(i=0; i<=end; i++)
    //     printf("%d ", map[i]);
    // printf("\n");

	for (r = 0; r < 2*K+1 && r<=end; r++)
		now += map[r];
	max = now;

	// printf("%d %d %d\n", f-1, r-1, now);

	while (r <= end)
	{
		now -= map[f++];
		now += map[r++];

		// printf("%d %d %d\n", f-1, r-1, now);

		if (max < now) max = now;
	}

	printf("%d\n", max);

	return 0;
}