#include <stdio.h>

int main(void)
{
    int N, K, i, j, idx;
    int arr[1000];
    int num;

    scanf("%d %d", &N, &K);
    num = N;

    for(i=0; i<N; i++)
        arr[i] = i+1;


    idx = N;
    printf("<");

    while(num)
    {
        for(j=0; j<K; )
        {
            idx++;
            idx %= N+1;
            if(arr[idx]) j++;
        }

        if(num!=1)
            printf("%d, ", arr[idx]);
        else
            printf("%d", arr[idx]);

        arr[idx] = 0;
        num--;        
    }
    printf(">\n");

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