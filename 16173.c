#include <stdio.h>
#include <stdlib.h>

int bfs(int **map, int **visit, int *queue, int N)
{
    int f, r, num, max = N*N*2;
    int x, y, nx, ny, i;
    int move[2][2] = {{0, 1},
                      {1, 0}};

    f=r=0;

    queue[r++] = 0;
    queue[r++] = 0;
    num = 2;

    while(num)
    {
        x = queue[f++];
        y = queue[f++];
        f %= max;
        num -= 2;

        if(map[x][y] == -1) return 1;

        for(i=0; i<2; i++)
        {
            nx = x + move[0][i]*map[x][y];
            ny = y + move[1][i]*map[x][y];

            if(0<=nx && nx<N && 0<=ny && ny<N)
            {
                if(visit[nx][ny] == 0)
                {
                    visit[nx][ny]=1;
                    queue[r++] = nx;
                    queue[r++] = ny;
                    r %= max;
                    num +=2;
                }
            }
        }   
    }
    return 0;
}


int main(void)
{
    int N, i, j, **map, **visit, *queue;
    scanf("%d", &N);

    map = (int **)calloc(N, sizeof(int *));
    visit = (int **)calloc(N, sizeof(int *));
    for(i=0; i<N; i++)
    {
        map[i] = (int *)calloc(N, sizeof(int));
        visit[i] = (int *)calloc(N, sizeof(int));
    }
    queue = (int *)calloc(N*N*2, sizeof(int));

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            scanf("%d", &map[i][j]);
            visit[i][j] = 0;
        }
            
    i = bfs(map, visit, queue, N);

    if(i)
        printf("HaruHaru\n");
    else
        printf("Hing\n");

    // for(i=0; i<N; i++)
    // {
    //     for(j=0; j<N; j++) 
    //         printf("%d ", visit[i][j]);
    //     printf("\n");
    // }

    for(i=0; i<N; i++)
    {
        free(visit[i]);
        free(map[i]);
    }
    free(map);
    free(visit);
    free(queue);
    return 0;
}