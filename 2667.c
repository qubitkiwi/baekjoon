#include <stdio.h>
#include <stdlib.h>

int apart[26][26] = {0,};
int V[26][26] = {0, };
int queue[26*26];

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) 
        return -1; 
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int bfs(int x, int y, int N)
{
    int mx, my, dx, dy;
    int max = 26*26;
    int num, f, r, i, cnt=0;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};

    f=r=num =0;

    queue[r++] = x;
    queue[r++] = y;

    V[x][y] = 1;

    r%=max;
    num += 2;

    while(num)
    {
        dx = queue[f++];
        dy = queue[f++];
        cnt++;

        f%= max;
        num -= 2;

        for(i=0; i<4; i++)
        {
            mx = dx + move[0][i];
            my = dy + move[1][i];

            if(0<mx && mx<=N && 0<my && my<=N)
            {
                if(apart[mx][my] == 1 && V[mx][my] == 0)
                {
                    V[mx][my] = 1;
                    queue[r++] = mx;
                    queue[r++] = my;
                    r%=max;
                    num += 2;
                }
            }
        }
    }
    return cnt;
}


int main(void)
{
    int N, i, j, sp=0;
    int block[25*25] = {0, };
    char s[26];

    scanf("%d", &N);

    for(i=1; i<=N; i++)
    {
        scanf("%s", s);
        for(j=0; j<N; j++)
        {
            apart[i][j+1] = s[j]-'0';
        }
    }

    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            if(apart[i][j]==1 && V[i][j] == 0)
            {
                block[sp++] = bfs(i, j, N);
            }
        }
    }

    qsort(block, sp, sizeof(int), compare);

    printf("%d\n", sp);
    for(i=0; i<sp; i++)
        printf("%d\n", block[i]);

    return 0;
}


// int dfs(int x, int y, int N)
// {
//     int i, mx, my, t=0;
//     int move[2][4] = {{1, -1, 0, 0},
//                       {0, 0, 1, -1}};

//     V[x][y] = 1;

//     for(i=0; i<4; i++)
//     {
//         mx = x+move[0][i];
//         my = y+move[1][i];
//         if(0<mx && mx <=N && 0<my && my<=N)
//         {
//             if(apart[mx][my] ==1 && V[mx][my] == 0)
//             {
//                 return dfs(mx, my, N)+1;
//             }
//         }
//     }
//     return t+1;
// }