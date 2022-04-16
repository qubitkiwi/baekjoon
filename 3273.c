#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M, i, j, cnt=0;
    int *arr;
    scanf("%d", &N);

    arr = malloc(N*sizeof(int));
    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);

    for(i=0; i<N; i++)
    {
        if(arr[i] == 0 || arr[i] >= M)
        {
            continue;
        }
        for(j=i; j<N; j++)
        {
            if(arr[j] == 0)
            {
                continue;
            }
            if((arr[i] + arr[j] == M) && i!=j)
            {
                cnt++;
                arr[i] = 0;
                arr[j] = 0;
                break;
            }
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}