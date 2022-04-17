#include <stdio.h>

int map[126][126];
int dist[126][126];
int queue[126*126];

void dijkstra(int N)
{
    int f, r, num, max=126*126;
    int x, y, nx, ny;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};

    f = r =0;
    
    dist[0][0] = map[0][0];

    queue[r++] = 0;
    queue[r++] = 0;
    num = 2;

    while(num)
    {
        x = queue[f++];
        y = queue[f++];
        f %= max;
        num -=2;

        if(x==N-1 && y==N-1)
            continue;

        for (int i = 0; i < 4; i++)
        {
            nx = x + move[0][i];
            ny = y + move[1][i];
            if(nx == 0 && ny ==0)
                continue;
            if(0<=nx && nx<N && 0<=ny && ny<N)
            {
                if(dist[x][y]+map[nx][ny] < dist[nx][ny])
                {
                    dist[nx][ny] = dist[x][y]+map[nx][ny];

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
    int N, i, j;
    long  count=0;

    while(1)
    {
        scanf("%d", &N);
        if(N == 0)
            break;
        
        count++;

        // 입력, 초기화
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                scanf("%d", &map[i][j]);
                dist[i][j] = __INT_MAX__;
            }
        }

        dijkstra(N);
        
        printf("Problem %ld: %d\n", count, dist[N-1][N-1]);
    }
    return 0;
}