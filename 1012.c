#include <stdio.h>

int map[50][50] = {0,};
int V[50][50] = {0, };
int queue[50*50*2];


int bfs(int N, int M)
{
    int max=50*50*2, num, f, r;
    int i, j, k, x, y, mx, my, cnt=0, chek;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};


    while(1)
    {
        chek=i=j=f=r= 0;
        for(; i<N; i++)
        {
            for(; j<M; j++)
            {
                if(map[i][j] == 1 && V[i][j] == 0)
                {
                    queue[r++] = i;
                    queue[r++] = j;
                    V[i][j] = 1;
                    num = 2;
                    chek=1;
                    break;
                }
            }
            if(chek==1) break;
            j=0;
        }

        if(chek==0) break;
        cnt++;

        while(num)
        {
            x = queue[f++];
            y = queue[f++];
            f%=max;
            num -= 2;

            for(k=0; k<4; k++)
            {
                mx = x + move[0][k];
                my = y + move[1][k];

                if(0<=mx && mx<N && 0<=my && my<M)
                {
                    if(map[mx][my]==1 && V[mx][my]==0)
                    {
                        queue[r++] = mx;
                        queue[r++] = my;
                        r%=max;
                        V[mx][my] = 1;
                        num += 2;
                    }
                }
            }
        }
    }
    return cnt;
}


int main(void)
{
    int tc, N, M, K, i, j, cnt;

    scanf("%d", &tc);
    while(tc--)
    {   
        scanf("%d %d %d", &M, &N, &K);

        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                map[i][j] = 0;
                V[i][j] = 0;
            }
        }

        while(K--)
        {
            scanf("%d %d", &i, &j);
            map[j][i] = 1;
        }

        cnt = bfs(N, M);

        printf("%d\n", cnt);
    }
    return 0;
}