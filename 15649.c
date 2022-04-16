#include <stdio.h>

int recode[9];
int V[9];

void tracking(int x, int n, int m)
{
    int i;

    if(x==m)
    {
        for(i=0; i<m; i++)
            printf("%d ", recode[i]);
        printf("\n");
        return ;
    }

    for(i=1; i<=n; i++)
    {
        if(V[i] == 0)
        {
            recode[x] = i;
            V[i] = 1;
            tracking(x+1, n, m);
            V[i] = 0;
        }
    }
}

int main(void)
{
    int N, M, i, j;

    scanf("%d %d", &N, &M);

    tracking(0, N, M);
    return 0;
}