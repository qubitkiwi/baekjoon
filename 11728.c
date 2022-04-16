#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M, i, j;
    int *A, *B;
    scanf("%d %d", &N, &M);

    A = malloc(N*sizeof(int));
    B = malloc(M*sizeof(int));

    for(i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }
    
    for(i=0; i<M; i++)
    {
        scanf("%d", &B[i]);
    }

    i=0;
    j=0;

    while(i<N || j<M)
    {
        if(i<N)
        {
            if(A[i] <= B[j] || j >= M )
            {
                printf("%d ", A[i++]);
            }
        }
        else if(j<M)
        {
            printf("%d ", B[j++]);
        }

        if(j<M)
        {
            if(A[i] > B[j] || i >= N)
            {
                printf("%d ", B[j++]);
            }
        }
        else if(i<N)
        {
            printf("%d ", A[i++]);
        }

    }
    return 0;
}