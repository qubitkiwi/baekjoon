#include <stdio.h>
#include <stdlib.h>

void dijkstra(char **map, int **dist, int *queue, int N, int M)
{
    int f, r, num, max=N*M*2;
    int x, y, nx, ny;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};

    f = r =0;
    
    dist[0][0] = map[0][0] - '0';

    queue[r++] = 0;
    queue[r++] = 0;
    num = 2;

    while(num)
    {
        x = queue[f++];
        y = queue[f++];
        f %= max;
        num -=2;

        if(x==N-1 && y==M-1)
            continue;
        
        for (int i = 0; i < 4; i++)
        {
            nx = x + move[0][i];
            ny = y + move[1][i];
            if(nx == 0 && ny ==0)
                continue;
            if(0<=nx && nx<N && 0<=ny && ny<M)
            {
                if(dist[x][y]+map[nx][ny]-'0' < dist[nx][ny])
                {
                    dist[nx][ny] = dist[x][y]+map[nx][ny]-'0';
                    
                    queue[r++] = nx;
                    queue[r++] = ny;
                    r %= max;
                    num += 2;
                }
            }   
        }
    }
}


int main(void)
{
    int N, M, i, j;
    int **dist, *queue;
    char **map;

    scanf("%d %d", &M, &N);

    map = (char **)malloc(N*sizeof(char *));
    for(i=0; i<N; i++)
        map[i] = (char *)malloc(M*sizeof(char));
    
    dist = (int **)malloc(N*sizeof(int*));
    for(i=0; i<N; i++)
        dist[i] = (int *)malloc(M*sizeof(int));

    queue = (int *)malloc(N*M*2*sizeof(int));

    for(i=0; i<N; i++)
        scanf("%s", map[i]);
    
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            dist[i][j] = __INT_MAX__;
    

    dijkstra(map, dist, queue, N, M);
    printf("%d\n", dist[N-1][M-1]);

    return 0;
}