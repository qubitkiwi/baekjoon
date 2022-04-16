#include <stdio.h>

int main(void)
{
    int N, i, j;
    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        for(j=0; j<i; j++)
            printf(" ");
        for(j=1; j<2*(N-i); j++)
            printf("*");

        printf("\n");
    }

    return 0;
}