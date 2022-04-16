#include <stdio.h>

int main(void)
{
    int N, M, i, j, p_min=0, sum=0;
    int p[1000001]={0,};
    scanf("%d", &N);
    scanf("%d", &M);

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
            if(p_min == 0)
            {
                p_min = i;
            }
            sum += i;
        }
    }

    if(sum > 0)
    {
        printf("%d\n%d\n", sum, p_min);
    }
    else
    {
        printf("-1\n");
    }
    

    return 0;
}