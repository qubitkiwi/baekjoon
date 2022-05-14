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

int main()
{
    int N, M, *A, t, i, *ptr;
    scanf("%d", &N);
    A = calloc(N, sizeof(int));
    for(i=0; i<N; i++)
        scanf("%d", &A[i]);
    qsort(A, N, sizeof(int), compare);

    scanf("%d", &M);
    while(M--)
    {
        scanf("%d", &t);
        ptr = bsearch(&t, A, N, sizeof(int), compare);
        if(ptr == NULL)
            printf("0 ");
        else
            printf("1 ");
    }
    printf("\n");

    free(A);
    return 0;
}