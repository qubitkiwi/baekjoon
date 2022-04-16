#include <stdio.h>

int main(void)
{
    int T, tc, i, N, day, t, sum;

    scanf("%d", &T);
    for(tc=0; tc<T; tc++)
    {
        day = 1;
        sum =0;
        scanf("%d", &N);

        for (i = 0; i < 6; i++)
        {
            scanf("%d", &t);
            sum += t;
        }

        while(sum<=N)
        {
            sum = sum*4;
            day++;
        }
        
        printf("%d\n", day);
        
    }

    return 0;
}