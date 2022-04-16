#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int i, j;
    int sum, count = 0;
    int *A;


    scanf("%d %d", &n, &m);
    A = calloc(n, sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
    }

    for(i=0; i<n; i++)
    {
        sum = 0;
        for(j=0; j<n-i; j++)
        {
            sum += A[i+j];
            if(sum == m)
            {
                count++;
                break;
            }
            if(sum > m)
                break;
        }
    }

    printf("%d", count);

    free(A);
    return 0;
}