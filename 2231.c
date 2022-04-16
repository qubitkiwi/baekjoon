#include <stdio.h>

int main(void)
{
    int N, M, i, j, anw=0, t;
    scanf("%d", &N);

    for(i=N; i>0; i--)
    {
        t = i;
        M = i;
        for(j=1000000; j>0; j/=10)
        {
            if(M/j)
            {
                t += M/j;
                M %= j;                
            }
        }
        if(N == t) anw = i;
    }


    printf("%d\n", anw);    

    return 0;
}