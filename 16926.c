#include <stdio.h>

int** make_arr(int r, int l)
{
    int ** arr = (int **)calloc(r, sizeof(int));
    for(int i=0; i<r; i++)
        arr[i] = (int *)calloc(l, sizeof(int));
    return arr;
}

void rm_arr(int **arr, int r)
{
    for (int i = 0; i < r; i++)
        free(arr[i]);
    free(arr);    
}

int** rotation(int **arr, int N, int M, int R)
{
    int i, j, layer, x, y, nx, ny;
    int **result = make_arr(N, M);

    if(N < M) layer = N/2;
    else layer = M/2;

    x = y = 0;

    while(layer--)
    {
        

    }

    return result;
}

int main(void)
{
    int N, M, R, i, j;
    int **arr, **anw;
    
    scanf("%d %d %d", &N, &M, &R);
    arr = make_arr(N, M);
    anw = make_arr(N, M);

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            scanf("%d", &arr[i][j]);
    
    anw = rotation(arr, N, M, R);

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
            printf("%d ", anw[i][j]);
        printf("\n");
    }

    rm_arr(arr, N);
    rm_arr(anw, N);
    return 0;
}




