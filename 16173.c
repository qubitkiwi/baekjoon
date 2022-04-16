#include <stdio.h>

int map[3][3];
int visit[3][3]={0,};
int queue[3*3];

int bfs(int N)
{
    int f, r, num, max;
    int x, y, nx, ny, i;
    int move[2][2] = {{0, 1},{1, 0}};

    f=r=num=0;
    max = 3*3;

    x = 0;
    y = 0;
    queue[r++] = x;
    queue[r++] = y;
    num += 2;

    while(num)
    {
        visit[x][y]=1;
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
                if(!visit[nx][ny])
                {
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
    int N, i, j;

    scanf("%d", &N);

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &map[i][j]);
    
    if(bfs(N))
        printf("HaruHaru\n");
    else
        printf("Hing\n");

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++) 
            printf("%d ", visit[i][j]);
        printf("\n");
    }

    return 0;
}