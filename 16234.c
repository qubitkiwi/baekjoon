#include <stdio.h>
#include <stdlib.h>

int map[50][50]={0,};
int V[50][50]={0,};
int queue[50*50];

int bfs(int N, int L, int R)
{
    int f, r, num, max;
    int day, i, j, x, y, nx, ny;
    f=r=num=0; max = 50*50;


    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            map[i][j] = 0;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {

        }
    }



    queue[r++] = 





    

    return day;
}

int main(void)
{
    int N, L, R, i, j, day=0;
    scanf("%d %d %d", &N, &L, &R);

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &map[i][j]);

    day = bfs(N, L, R);
    printf("%d\n", day);

    return 0;
}