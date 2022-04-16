#include <stdio.h>

int tree[8] = {0,};
int V[8] = {0,};

void dfs(int d, int N, int M)
{
    int i;

    if(d == M)
    {
        for(i=0; i<M; i++)
            printf("%d ", tree[i]);
        printf("\n");
        return ;
    }

    for(i=1; i<=N; i++)
    {

        V[i] = 1;
        tree[d] = i;
        dfs(d+1, N, M);
        V[i] = 0;
    }
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    dfs(0, N, M);

    return 0;
}