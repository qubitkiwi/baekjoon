#include <stdio.h>

int main(void)
{
    int N, M, i, j, p_cnt;
    int p[1000001]={0,};

    p[1] = 1;

    while(1)
    {
        p_cnt = 0;
        scanf("%d", &N);

        if(N==0)
        {
            break;
        }

        for(i=2; i<=2*N; i++)
        {
            if(p[i] == 1)
            {
                continue;
            }
            for(j=2; j*i<=2*N; j++)
            {
                p[i*j] = 1;
            }
        }

        for(i=N+1; i<=2*N; i++)
        {
            if(p[i] == 0)
            {
                p_cnt++;
            }
        }

        printf("%d\n", p_cnt);
    }

    return 0;
}