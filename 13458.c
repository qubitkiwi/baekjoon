#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, B, C;
    int *A;
    int i;
    long long people;


    scanf("%d", &N);

    A = malloc(N*sizeof(int));
    for(i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d %d", &B, &C);

    people = N;

    for(i=0; i<N; i++)
    {

        people += (A[i]-B)/C;
        
        if(A[i]%C > 0)
        {
            people++;
        }
    }

    printf("%lld\n", people);

    free(A);
    return 0;
}
