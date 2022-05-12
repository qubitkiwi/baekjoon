#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A, B, C, N, i;
    long long people=0;

    scanf("%d", &N);

    A = malloc(N*sizeof(int));
    for(i=0; i<N; i++)
        scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);

    // people = N;

    for(i=0; i<N; i++)
    {
        A[i] = A[i]- B;
        people++;

        if(A[i] > 0)
        {
            people += A[i]/C;
            
            if(A[i]%C > 0)
                people++;
        }
    }
    printf("%lld\n", people);

    free(A);
    return 0;
}
