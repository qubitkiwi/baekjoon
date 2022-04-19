#include <stdio.h>

int bfs(int (*map)[50], int (*visit)[50], int* queue, int w, int h)
{
    int f, r, num, chek, max=50*50*2;
    int x, y, nx, ny, i, j, island=0;
    int move[2][8] = {{0, 0, 1,-1, 1, 1,-1,-1},
                      {1,-1, 0, 0, 1,-1, 1,-1}};

    while(1)
    {   
        f=r=num = 0;
        chek=0;

        for(i=0; i<h; i++)
        {
            for(j=0; j<w; j++)
            {
                if(map[i][j] == 1 && visit[i][j] == 0)
                {
                    visit[i][j] = 1;
                    queue[r++] = i;
                    queue[r++] = j;
                    num=2;
                    chek = 1;
                }
                if(chek==1) break;
            }
            if(chek==1) break;
        }
        if(chek == 0)
            break;
        island++;

        while(num)
        {
            x = queue[f++];
            y = queue[f++];
            f %= max;
            num -= 2;

            for(i=0; i<8; i++)
            {
                nx = x + move[0][i];
                ny = y + move[1][i];

                if(0<=nx && nx<h && 0<=ny && ny<w)
                {
                    if(map[nx][ny] == 1 && visit[nx][ny]==0)
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
    return island;
}

int main(void)
{
    int w, h, i, j, island;
    int map[50][50], queue[50*50*2], visit[50][50];


    while(1)
    {
        scanf("%d %d", &w, &h);
        if(w==0 && h==0)
            break;

        for(i=0; i<h; i++)
            for(j=0; j<w; j++)
            {
                scanf("%d", &map[i][j]);
                visit[i][j] = 0;
            }
        
        island = bfs(map, visit, queue, w, h);

        printf("%d\n", island);
    }

    return 0;
}