#include <stdio.h>
#include <stdlib.h>

void resetarr(int **arr, int n)
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            arr[i][j] = 0;

}

int** emptysquare(int size)
{
    int** result = (int**)malloc(sizeof(int*) * (size));
    for(int i=0; i<size; i++)
        result[i] = (int*)calloc(size, sizeof(int));
    return result;
}

void freesquare(int **arr)
{
    int i, n;
    n = sizeof(arr)/sizeof(int);
    for(i=0; i<n; i++)
        free(arr[i]);
    free(arr);
}

int bfs(int d,int n, int **map, int **V, int *q)
{
    int f, r, num, q_max;
    int area=0, i, j, x, y, mx, my, chek=0;
    int move[2][4] = {{1, -1, 0, 0},
                      {0, 0, 1, -1}};

    f=r=num=0; 
    q_max = (n+1)*(n+1);

    resetarr(V, n+1);
    
    

    while(1)
    {
        chek = 0;
        for(x=1; x<=n; x++)
        {
            for(y=1; y<=n; y++)
            {
                printf("%d %d\n", x, y);
                if(map[x][y] > d && V[x][y] == 0)
                {
                    chek=1;
                    break;
                }    
            }
            if(chek == 1) break;
        }
        
        printf("%d %d %d %d %d\n", x, y, V[x][y], map[x][y], d);
        if(x==n && y==n && !chek )
            break;
        
        area++;

        q[r++] = x;
        q[r++] = y;
        r%=q_max;
        num += 2;

        while(num)
        {
            x = q[f++];
            y = q[f++];
            f%=q_max;
            num -= 2;

            for(i=0; i<4; i++)
            {
                mx = x +move[0][i];
                my = y +move[1][i];
                if(0<mx && mx<=n && 0<my && my<=n)
                {
                    if(map[mx][my] > d && V[mx][my]==0)
                    {
                        V[mx][my] = 1;
                        q[r++] = mx;
                        q[r++] = my;
                        r%=q_max;
                        num += 2;
                    }
                }
            }
        }
    }
    return area;
}

int main(void)
{
    int n, i, j, d, t, max=0;
    int **map, **V, *q;

    scanf("%d", &n);

    map = emptysquare(n+1);
    V = emptysquare(n+1);
    q = (int *)malloc((n+1)*(n+1)*sizeof(int));

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    printf("%d\n", map[5][5]);

    for(d=1; (t=bfs(d, n, map, V, q)); d++)
    {
        if(max < t)
            max = t;
    }

    printf("%d\n", max);
    
    freesquare(map);
    freesquare(V);
    return 0;
}


// map, V, n, queue, d