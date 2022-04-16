#include <stdio.h>

int graph[1001][1001]={0, };
int d_visited[1001] = {0, };
int b_visited[1001] = {0, };
int queue[1001];

void dfs(int V, int N)
{
    int i;
    d_visited[V] = 1;
    printf("%d ", V);

    for(i=1; i<=N; i++)
    {
        if(graph[V][i]==1 && d_visited[i]==0)
        {
            d_visited[i] = 1;
            dfs(i, N);
        }
    }

}

void bfs(int V, int N)
{
    int f, r, p, i;
    f=r=0;

    printf("%d ", V);
    b_visited[V] = 1;
    queue[r++] = V;

    while(f<r)
    {
        p = queue[f++];
        for(i=1; i<=N; i++)
        {
            if(graph[p][i]==1 && b_visited[i]==0)
            {
                b_visited[i] = 1;
                queue[r++] = i;
                printf("%d ", i);
            }
        }
    }
}


int main(void)
{
    int N, M, V, i, j;
    scanf("%d %d %d", &N, &M, &V);

    while(M--)
    {
        scanf("%d %d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
    }

    dfs(V, N);
    printf("\n");
    bfs(V, N);

    return 0;
}