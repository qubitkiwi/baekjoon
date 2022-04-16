#include <stdio.h>

int graph[101][101] = {0,};
int d_v[101] = {0,};
int kinsip=0;

int dfs(int V, int W, int N)
{
    int i;
    
    d_v[V] = 1;
    if(V==W) return 1;
    
    for(i=1; i<=N; i++)
    {
        if(graph[V][i]==1 && d_v[i] == 0)
        {
            if(dfs(i, W, N))
            {
                kinsip++;
                return 1;
            }            
        }
    }
    return 0;
}

int main(void)
{
    int N, V, W, tc, i, j, t;
    scanf("%d", &N);
    scanf("%d %d", &V, &W);
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
    }

    dfs(V, W, N);
    kinsip = kinsip ? kinsip: -1;
    printf("%d\n", kinsip);   
    
    return 0;
}