#include <stdio.h>
#include <stdlib.h>

void dfs(char **arr, int N, int x, int y)
{
    int i, j, cnt_0=0;

    for(i=x; i<N+x; i++)
    {
        for(j=y; j<N+y; j++)
        {
            cnt_0 += arr[i][j]-'0';
        }
    }

    

    if(cnt_0 == 0)
    {
        printf("0");
    }
    else if(cnt_0 == N*N)
    {
        printf("1");
    }
    else
    {
        printf("(");
        dfs(arr, N/2, x, y);
        dfs(arr, N/2, x, y+N/2);
        dfs(arr, N/2, x+N/2, y);
        dfs(arr, N/2, x+N/2, y+N/2);
        printf(")");
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
        scanf("%s", arr[i]);

    dfs(arr, N, 0, 0);
    printf("\n");
    
    for(i=0; i<N; i++)
        free(arr[i]);
    free(arr);
    return 0;
}