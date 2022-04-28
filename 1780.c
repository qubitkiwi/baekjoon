#include <stdio.h>
#include <stdlib.h>

int paper[3] = {0, };

void dfs(int **map, int N, int x, int y)
{
    int i, j, zero=0, one=0, minus=0;

    for (i = x; i < x+N; i++)
    {
        for (j = y; j < y+N; j++)
        {
            if(map[i][j] == 0)
                zero++;
            else if(map[i][j] == 1)
                one++;
        }
    }
    minus = N*N -zero-one;

    if(zero == N*N)
    {
        paper[1]++;
    }
    else if(one == N*N)
    {
        paper[2]++;
    }
    else if(minus == N*N)
    {
        paper[0]++;
    }
    else
    {
        dfs(map, N/3, x, y);
        dfs(map, N/3, x, y+N/3);
        dfs(map, N/3, x, y+2*N/3);
        
        dfs(map, N/3, x+N/3, y);
        dfs(map, N/3, x+N/3, y+N/3);
        dfs(map, N/3, x+N/3, y+2*N/3);

        dfs(map, N/3, x+2*N/3, y);
        dfs(map, N/3, x+2*N/3, y+N/3);
        dfs(map, N/3, x+2*N/3, y+2*N/3);
    }
}

int main()
{
    int N, i, j, **map;
    scanf("%d", &N);

    map = (int **)calloc(N, sizeof(int *));
    for(i=0; i<N; i++)
        map[i] = (int *)calloc(N, sizeof(int));

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &map[i][j]);
    
    dfs(map, N, 0, 0);
    
    printf("%d\n%d\n%d\n", paper[0], paper[1], paper[2]);

    for(i=0; i<N; i++)
        free(map[i]);
    free(map);
    return 0;
}