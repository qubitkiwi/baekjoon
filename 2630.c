#include <stdio.h>
#include <stdlib.h>

int w=0, b=0;

void dfs(int **map, int x, int y, int N)
{
    int i, j, b_cnt=0;

    for(i=y; i<y+N; i++)
    {
        for(j=x; j<x+N; j++)
        {
            if(map[i][j] == 1)
            {
                b_cnt++;
            }
        }
    }

    if(b_cnt == 0)
    {   
        w++;
    }
    else if(b_cnt == N*N)
    {
        b++;
    }
    else
    {
        dfs(map, x, y, N/2);
        dfs(map, x+N/2, y, N/2);
        dfs(map, x, y+N/2, N/2);
        dfs(map, x+N/2, y+N/2, N/2);
    }
}

int main()
{
    int N, i, j, **map;

    scanf("%d", &N);

    map = (int **)calloc(N, sizeof(int*));
    for(i=0; i<N; i++)
        map[i] = (int *)calloc(N, sizeof(int));

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &map[i][j]);

    dfs(map, 0, 0, N);
    
    printf("%d\n%d\n", w, b);

    for(i=0; i<N; i++)
        free(map[i]);
    free(map);
    return 0;
}