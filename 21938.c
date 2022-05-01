#include <stdio.h>
#include <stdlib.h>

int queue[1000*1000*2];
int visit[1000][1000];

int **arr_mapped(int ***pic, int N, int M, int T)
{
    int i, j;
    int **avg = (int **)calloc(N, sizeof(int*));
    for(i=0; i<N; i++)
        avg[i] = (int *)calloc(M, sizeof(int));
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            avg[i][j] = (pic[i][j][0]+pic[i][j][1]+pic[i][j][2])/3 >= T;
        }
    }
    return avg;
}

int bfs(int **map, int N, int M)
{
    int f, r, num, max=1000*1000*2;
    int x, y, nx, ny;
    int i, j, k, object, chek;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};
    
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            visit[i][j] = 0;

    object = i = j= 0;

    while(1)
    {
        f=r=chek=0;
        for(; i<N; i++)
        {
            for(; j<M; j++)
            {
                if(map[i][j]==1 && visit[i][j] == 0)
                {
                    visit[i][j] = 1;
                    queue[r++] = i;
                    queue[r++] = j;
                    chek = 1;
                    num = 2;
                    break;
                }
            }
            if(chek==1) break;
            j=0;
        }

        if(chek==0) break;
        object++;

        while(num)
        {
            x = queue[f++];
            y = queue[f++];
            f %= max;
            num -= 2;

            for(k=0; k<4; k++)
            {
                nx = x + move[0][k];
                ny = y + move[1][k];
                if(0<=nx && nx<N && 0<=ny && ny<M)
                {
                    if(map[nx][ny]==1 && visit[nx][ny] == 0)
                    {
                        visit[nx][ny] = 1;
                        queue[r++] = nx;
                        queue[r++] = ny;
                        r %= max;
                        num += 2;
                    }
                }
            }
        }
    }
    return object;
}   


int main()
{
    int N, M, T, i, j, k, object, ***picture, **map;
    scanf("%d %d", &N, &M);

    picture = (int ***)calloc(N, sizeof(int **));
    for(i=0; i<N; i++)
    {
        picture[i] = (int **)calloc(M, sizeof(int*));
        for(j=0; j<M; j++)
        {
            picture[i][j] = (int *)calloc(3, sizeof(int));
        }
    }

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            for(k=0; k<3; k++)
                scanf("%d", &picture[i][j][k]);

    scanf("%d", &T);

    map = arr_mapped(picture, N, M, T);

    object = bfs(map, N, M);

    printf("%d\n", object);

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            free(picture[i][j]);
        }
        free(picture[i]);
    }
    free(picture);

    for(i=0; i<N; i++)
        free(map[i]);
    free(map);
    return 0;
}