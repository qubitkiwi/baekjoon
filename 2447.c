#include <stdio.h>
#include <stdlib.h>

void dfs(char **arr, int N, int x, int y)
{
    int i, j;

    for(i=x+N/3; i<x+2*N/3; i++)
    {
        for(j=y+N/3; j<y+2*N/3; j++)
        {
            arr[i][j] = ' ';
        }
    }

    if(N>1)
    {
        dfs(arr, N/3, x, y);
        dfs(arr, N/3, x, y+N/3);
        dfs(arr, N/3, x, y+2*N/3);

        dfs(arr, N/3, x+N/3, y);
        dfs(arr, N/3, x+N/3, y+N/3);
        dfs(arr, N/3, x+N/3, y+2*N/3);

        dfs(arr, N/3, x+2*N/3, y);
        dfs(arr, N/3, x+2*N/3, y+N/3);
        dfs(arr, N/3, x+2*N/3, y+2*N/3);   
    }
}

int main(void)
{
    int N, i, j;
    char **arr;
    scanf("%d", &N);

    arr = (char **)calloc(N, sizeof(char *));
    for(i=0; i<N; i++)
        arr[i] = (char *)calloc(N, sizeof(char));

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            arr[i][j] = '*';

    dfs(arr, N, 0, 0);

    for(i=0; i<N; i++)
        printf("%s\n", arr[i]);

    for(i=0; i<N; i++)
        free(arr[i]);
    free(arr);
    return 0;
}