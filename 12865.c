#include <stdio.h>
#include <stdlib.h>

int** emptysquare(int size){
    int** result = (int**)malloc(sizeof(int*) * size);
    for(int i=0; i<size; i++)
        result[i] = (int*)calloc(size, sizeof(int));
    return result;
}

int** make_arr(int r, int l)
{
    int ** arr = (int **)calloc(r, sizeof(int));
    for(int i=0; i<r; i++)
        arr[i] = (int *)calloc(l, sizeof(int));
    return arr;
}

int main(void)
{
    int N, K, i, j;
    int **object;
    scanf("%d %d", &N, &K);

    object = make_arr(N, 2);

    for(i=0; i<N; i++)
        scanf("%d %d", &object[i][0], &object[i][1]);

    for (i = 0; i < N; i++)
    {
        printf("%d %d\n", object[i][0], object[i][1]);
    }
    printf("\n");



    return 0;
}