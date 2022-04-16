#include <stdio.h>

int main(void)
{
    int tc, V, E, i, j, tree[20001][20001];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d", &V, &E);
        for(i=0; i<=V; i++)
            for(j=0; j<=V; j++)
                tree[i][j] = 0;

        while(E--)
        {
            scanf("%d %d", &i, &j);
            tree[i][j] = 1;
            tree[j][i] = 1;
        }
        




    }
    return 0;
}