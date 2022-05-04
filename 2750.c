#include <stdio.h>
#include <stdlib.h>

int compar(const void *a,const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1<num2)
        return -1;
    if(num1>num2)
        return 1;
    return 0;
}

int main(void)
{
    int N, i, j, last, t;
    int *arr;

    scanf("%d", &N);
    arr = malloc(N*sizeof(int));

    for(i=0; i<N; i++)
        scanf("%d", &arr[i]);
    
    qsort(arr, N, sizeof(int), compar);

    for(i=0; i<N; i++)
        printf("%d\n", arr[i]);

    free(arr);
    return 0;
}