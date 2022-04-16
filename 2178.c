#include <stdio.h>

int maze[101][101] = {0,};
int V[101][101] = {0, };
int queue[101*101];

int bfs(int x, int y, int N, int M)
{
    int max = 101*101;
    int num = 0;

    int f, r, i, j;
    int mx, my;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};
    f=r=0;

    queue[r++] = x;
    queue[r++] = y;

    r = r%max;
    num += 2;

    while(num)
    {
        x = queue[f++];
        y = queue[f++];

        f = f%max;
        num -= 2;


        V[x][y] = 1;

        if(x==N && y==M)
            return 1;

        for(i=0; i<4; i++)
        {
            mx = x+move[0][i];
            my = y+move[1][i];

            if(0<mx && mx<=N && 0<my && my<=M)
            {
                if(maze[mx][my] == 1 && V[mx][my] == 0)
                {
                    maze[mx][my] = maze[x][y]+1;
                    queue[r++] = mx;
                    queue[r++] = my;

                    r = r%max;
                    num += 2;
                }
            }
        }
    }
}

int main(void)
{
    int N, M, i, j, a, b;
    char s[101];
    scanf("%d %d", &N, &M);

    for(i=1; i<=N; i++)
    {
        scanf("%s", s);        
        for(j=0; j<M; j++)
        {
            maze[i][j+1] = s[j]-'0';
        }
    }

    bfs(1, 1, N, M);
    printf("%d\n", maze[N][M]);

    return 0;
}