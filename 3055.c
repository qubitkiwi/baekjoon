#include <stdio.h>

char map[50][50];
int V[50][50] = {0, };
int queue[50*50];


void water_bfs(int R, int C)
{
    int f, r, num, max;
    int i, j, x, y, nx, ny;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};

    f=r=num=0;
    max = 50*50;

    for(i=0; i<R; i++)
        for(j=0; j<C; j++)
            if(map[i][j] == '*')
            {
                V[i][j] = 1;
                queue[r++] = i;
                queue[r++] = j;
                num += 2;
            }
    
    while(num)
    {
        x = queue[f++];
        y = queue[f++];
        f %= max;
        num -= 2;

        for(i=0; i<4; i++)
        {
            nx = x + move[0][i];
            ny = y + move[1][i];

            if(0<=nx && nx<R && 0<=ny && ny<C)
            {
                if(V[nx][ny] == 0 && map[nx][ny] == '.')
                {
                    
                    V[nx][ny] = V[x][y] + 1;
                    queue[r++] = nx;
                    queue[r++] = ny;
                    r %= max;
                    num += 2;
                }
            }
        }
    }
}

int hedgehog_bfs(int R, int C)
{
    int f, r, num, max;
    int i, j, x, y, nx, ny, chek=0;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};

    f=r=num=0;
    max = 50*50;

    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            if(map[i][j] == 'S')
            {
                V[i][j] = 1;
                queue[r++] = i;
                queue[r++] = j;
                num += 2;
                chek = 1;
                break;
            }
        }
        if(chek) break;
    }

    chek = 0;
    
    while(num)
    {
        x = queue[f++];
        y = queue[f++];
        f %= max;
        num -= 2;

        for(i=0; i<4; i++)
        {
            nx = x + move[0][i];
            ny = y + move[1][i];

            if(0<=nx && nx<R && 0<=ny && ny<C)
            {
                if((V[nx][ny]>V[x][y]+1 || V[nx][ny] == 0) && map[nx][ny] == '.')
                {
                    V[nx][ny] = V[x][y] + 1;
                    queue[r++] = nx;
                    queue[r++] = ny;
                    r %= max;
                    num += 2;
                }

                if(map[nx][ny] == 'D')
                    return V[x][y];
            }
        }
    }
    return 0;
}



int main(void)
{
    int R, C, i, j, anw=0;

    scanf("%d %d", &R, &C);

    for(i=0; i<R; i++)
        scanf("%s", map[i]);

    
    water_bfs(R, C);

    printf("\n");

    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            printf("%d ", V[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    anw = hedgehog_bfs(R, C);

        for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            printf("%d ", V[i][j]);
        }
        printf("\n");
    }

    if(anw)
        printf("%d\n", anw);
    else
        printf("KAKTUS\n");

    return 0;
}