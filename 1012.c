#include <stdio.h>

int map[50][50] = {0,};
int V[50][50] = {0, };
int queue[50*50];


void bfs(int x, int y, int N, int M)
{
    int max=50*50, num, f, r;
    int i, j, mx, my, tx, ty;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};

    num = f = r = 0;

    queue[r++] = x;
    queue[r++] = y;

    r%=max;
    num += 2;

    while(num)
    {
        tx = queue[f++];
        ty = queue[f++];

        V[tx][ty] = 1;

        f%=max;
        num -= 2;

        for(i=0; i<4; i++)
        {
            mx = tx + move[0][i];
            my = ty + move[1][i];

            if(0<=mx && mx<N && 0<=my && my<M)
            {
                if(map[mx][my]==1 && V[mx][my]==0)
                {
                    queue[r++] = mx;
                    queue[r++] = my;

                    r%=max;
                    num += 2;
                }
            }
        }
    }
}


int main(void)
{
    int tc, N, M, K, i, j, cnt;

    scanf("%d", &tc);
    while(tc--)
    {
        cnt=0;
        
        for(i=0; i<50; i++)
        {
            for(j=0; j<50; j++)
            {
                map[i][j] = 0;
                V[i][j] = 0;
            }
        }

        scanf("%d %d %d", &N, &M, &K);
        while(K--)
        {
            scanf("%d %d", &i, &j);
            map[i][j] = 1;
        }

        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                if(map[i][j]==1 && V[i][j]==0)
                {
                    cnt++;
                    bfs(i, j, N, M);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}