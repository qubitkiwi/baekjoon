#include <stdio.h>

int main(void)
{
    int N, M, i, j, p_cnt=0, t;
    int p[1001]={0,};

    p[1] = 1;


    for(i=2; i<1001; i++)
        {
            if(p[i] == 1)
            {
                continue;
            }
            for(j=2; j*i<1001; j++)
            {
                p[i*j] = 1;
            }
        }

    scanf("%d", &N);


    for(i=0; i<N; i++)
    {
        scanf("%d", &t);
        if(p[t]==0)
        {
            p_cnt++;
        }
    }


    printf("%d\n", p_cnt);
    

    return 0;
}