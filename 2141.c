#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j, T, idx=0, min=0;
    int X[100000];
    int A[100000];
    int D[100000]={0,};
    scanf("%d", &N);

    for(T=0; T<N; T++)
    {
        scanf("%d %d", &X[T], &A[T]);
    }

    for(i=1; i<N; i++)
    {
        D[0] += i*A[i];
    }
    min = D[0];

    for(i=1; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            D[i] += abs(i-j)*A[j];
        }
        if(min > D[i])
        {
            min = D[i];
            idx = i;
        }
    }
    for(i=0; i<N; i++)
    {
        printf("%d  ", D[i]);
    }


    printf("\n%d\n", idx+1);

    return 0;
}