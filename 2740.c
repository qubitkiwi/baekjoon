#include <stdio.h>
#include <stdlib.h>

int** make_arr(int r, int l)
{
    int ** arr = (int **)malloc(r*sizeof(int*));
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

int** multiply(int **A, int **B, int n, int m, int l, int k)
{
    int i, j, h;
    int **result =  make_arr(n, k);    

    for(i=0; i<n; i++)
        for(j=0; j<k; j++)
            result[i][j] = 0;

    for(i=0; i<n; i++)
        for(j=0; j<k; j++)
            for(h=0; h<m; h++)
                result[i][j] += A[i][h]*B[h][j];

    return result;
}

int main(void)
{
    int n, m, k, l, i, j, h;
    int **A, **B, **C;

    scanf("%d %d", &n, &m);
    A = make_arr(n, m);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &A[i][j]);

    scanf("%d %d", &l, &k);
    B = make_arr(l, k);
    for(i=0; i<l; i++)
        for(j=0; j<k; j++)
            scanf("%d", &B[i][j]);

    C = multiply(A, B, n, m, l, k);

    for(i=0; i<n; i++)
    {
        for(j=0; j<k; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    rm_arr(A, n);
    rm_arr(B, l);
    rm_arr(C, n);
    return 0;
}