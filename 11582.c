#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;

    return 0;
}

int main(void)
{
    int N, K, i, *chicken;
    scanf("%d", &N);

    chicken = (int *)calloc(N, sizeof(int));

    for(i=0; i<N; i++)
        scanf("%d", &chicken[i]);

    scanf("%d", &K);
    K = N/K;

    for(i=0; i<N; i+=K)
        qsort(&chicken[i], K, sizeof(int), compare);

    for(i=0; i<N; i++)
        printf("%d ", chicken[i]);
    printf("\n");

    free(chicken);
    return 0;
}