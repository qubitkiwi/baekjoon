#include <stdio.h>
#include <stdlib.h>

void dfs(int s, int d, int N, int M, int *recode)
{
    int i;

    if(d == M)
    {
        for(i=0; i<M; i++)
            printf("%d ", recode[i]);
        printf("\n");
        return ;
    }


    for(i=s; i<N+1; i++)
    {
        recode[d] = i;
        dfs(i, d+1, N, M, recode);
    }
}


int main(void)
{
    int N, M, i;
    int *recode;
    scanf("%d %d", &N, &M);

    recode = (int *)malloc((N+1)*sizeof(int));

    for(i=0; i<N+1; i++)    
        recode[i] = 0;

    dfs(1, 0, N, M, recode);

    free(recode);
    return 0;
}