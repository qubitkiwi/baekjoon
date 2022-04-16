#include <stdio.h>

int main(void)
{
    int N, M, i, j;
    int p[1000001]={0,};
    scanf("%d %d", &N, &M);

    p[1] = 1;

    for(i=2; i<=M; i++)
    {
        if(p[i] == 1)
        {
            continue;
        }
        for(j=2; j*i<=M; j++)
        {
            p[i*j] = 1;
        }
    }

    for(i=N; i<=M; i++)
    {
        if(p[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}