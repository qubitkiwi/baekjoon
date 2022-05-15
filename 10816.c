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

int high_thr(int key, int *A, int N)
{
    int f=0, r=N-1, m;
    while(f <= r)
    {
        m = (f+r)/2;
        if(key < A[m])
            r = m-1;
        else
            f = m+1;
    }
    return f;
}

int low_thr(int key, int *A, int N)
{
    int f=0, r=N-1, m;
    while(f <= r)
    {
        m = (f+r)/2;
        if(key <= A[m])
            r = m-1;
        else
            f = m+1;
    }
    return f;
}

int main()
{
    int N, M, *A, t, i, cnt;
    scanf("%d", &N);
    A = calloc(N, sizeof(int));
    for(i=0; i<N; i++)
        scanf("%d", &A[i]);
    qsort(A, N, sizeof(int), compare);

    scanf("%d", &M);
    while(M--)
    {
        scanf("%d", &t);
        cnt = high_thr(t, A, N) - low_thr(t, A, N);
        printf("%d ", cnt);
    }
    printf("\n");

    free(A);
    return 0;
}