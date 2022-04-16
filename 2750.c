#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j, last, t;
    int *arr;

    scanf("%d", &N);
    arr = malloc(N*sizeof(int));

    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    



    printf("\n");

    for(i=0; i<N; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}