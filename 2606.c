#include <stdio.h>

int grahp[101][101]={0, };
int d_v[101] = {0,};
int cnt=0;

void dfs(int V, int N)
{
    int i;
    d_v[V] = 1;
   
    for(i=1; i<=N; i++)
    {
        if(d_v[i]==0 && grahp[V][i] == 1)
        {
            d_v[i] = 1;
            cnt++;
            dfs(i, N);
        }
    }
}

int main(void)
{
    int N, tc, i, j;
    scanf("%d", &N);
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d", &i, &j);
        grahp[i][j] = 1;
        grahp[j][i] = 1;
    }

    dfs(1, N);
                
    printf("%d\n", cnt);

    return 0;
}