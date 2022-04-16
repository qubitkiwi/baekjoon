#include <stdio.h>

int V[301][301] = {0, };
int queue[301*301];

int bfs(int n, int *knight, int *goal)
{
    int f, r, num, max=301*301;
    int x, y, mx, my, i, j;
    int move[2][8] = {{2,  2, 1, 1, -1, -1, -2, -2},
                      {1, -1, 2, -2, -2, 2, 1, -1}};

    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            V[i][j] = 0;

    f=r=num=0;
    queue[r++] = knight[0];
    queue[r++] = knight[1];
    num += 2;

    V[knight[0]][knight[1]] = 1;

    while(num)
    {
        x = queue[f++];
        y = queue[f++];
        f %= max;
        num -= 2;

        if(x==goal[0] && y==goal[1])
            break;

        for(i=0; i<8; i++)
        {
            mx = x + move[0][i];
            my = y + move[1][i];

            if(0<=mx && mx<n && 0<=my && my<n)
            {
                if(V[mx][my] == 0)
                {
                    V[mx][my] = V[x][y] +1;
                    queue[r++] = mx;
                    queue[r++] = my;
                    r %= max;
                    num += 2;
                }
            }
        }
    }
    return V[x][y];
}

int main(void)
{
    int tc, n, knight[2], goal[2], anw;

    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        scanf("%d %d", &knight[0], &knight[1]);
        scanf("%d %d", &goal[0], &goal[1]);

        anw = bfs(n, knight, goal);

        printf("%d\n", anw-1);
    }
    return 0;
}