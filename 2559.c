#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, K, i, j, max, t;
    int *temp;
    scanf("%d %d", &N, &K);
    
    temp = malloc(N*sizeof(int));
    for(i=0; i<N; i++)
    {
        scanf("%d", &temp[i]);
    }

    max = 0;
    for(i=0; i<K; i++)
    {
        max += temp[i];
    }
    t = max;

    for(i=0; i+K<N; i++)
    {
        t -= temp[i];
        t += temp[i+K];

        if(max < t)
        {
            max = t;
        }
    }
    printf("%d\n", max);

    return 0;
}