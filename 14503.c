#include <stdio.h>
#include <stdlib.h>

int sol(int **map, int N, int M, int r, int c, int d)
{
    int i, clean=0, fall;
    int nr, nc, nd;
    int move[2][4] = {{-1, 0, 1, 0},
                      {0, 1, 0, -1}};

    if(map[r][c] == 0)
    {
        map[r][c] = 2;
        clean++;
    }

    while(1)
    {
        fall = 0;
        for(i=1; i<=4; i++)
        {
            nd = d-i >= 0 ? d-i : 4+d-i;
            nr = r + move[0][nd];
            nc = c + move[1][nd];
            if(0<=nr && nr<N && 0<=nc && nc<M)
            {
                if(map[nr][nc] == 0)
                {
                    map[nr][nc] = clean+2;
                    r = nr;
                    c = nc;                
                    d = nd;
                    clean++;
                    break;
                }
            }
            fall++;
        }

        if(fall == 4)
        {
            nd = (d+2)%4;
            nr = r + move[0][nd];
            nc = c + move[1][nd];
            if(nr<0 || N<=nr || nc<0 || M<=nc || (map[nr][nc] == 1))
            {
                return clean;
            }
            else
            {
                r = nr;
                c = nc;
            }
        }
    }
}

int main()
{
    int N, M, r, c, d, claen;
    int **map, i, j;
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);

    map = (int **)calloc(N, sizeof(int *));
    for(i=0; i<N; i++)
        map[i] = (int *)calloc(M, sizeof(int));
    
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            scanf("%d", &map[i][j]);

    claen = sol(map, N, M, r, c, d);
    
    printf("%d\n", claen);

    for(i=0; i<N; i++)
        free(map[i]);
    free(map);
    return 0;
}

/* 
북 0
동 1
남 2
서 3

 0
3 1
 2

 */