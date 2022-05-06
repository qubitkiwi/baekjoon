#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, K, *arr;
    int num, i, idx;
    scanf("%d %d", &N, &K);

    arr = (int *)calloc(N, sizeof(int));
    num = N;
    idx = N-1;

    for(i=0; i<N; i++)
        arr[i] = i+1;

    printf("<");

    while(num--)
    {
        for(i=0; i<K; )
        {
            idx = (idx+1)%N;
            if(arr[idx])
                i++;
        }

        if(num)
            printf("%d, ", arr[idx]);
        else
            printf("%d", arr[idx]);

        arr[idx] = 0;
    }
    printf(">\n");

    free(arr);
    return 0;
}


/*
7 3

1 2 3 4 5 6 7
1 2 * 4 5 6 7
1 2 * 4 5 * 7
1 * * 4 5 * 7
1 * * 4 5 * *
1 * * 4 * * *
* * * 4 * * *
* * * * * * *


*/