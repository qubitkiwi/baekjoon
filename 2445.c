#include <stdio.h>

int main(void)
{
    int N, i, j;
    scanf("%d", &N);

    for(i=1; i<N; i++)
    {
        for(j=0; j<i; j++)
            printf("*");
        for(j=0; j<2*(N-i); j++)
            printf(" ");
        for(j=0; j<i; j++)
            printf("*");
        printf("\n");
    }
    for(i=N; i>0; i--)
    {
        for(j=0; j<i; j++)
            printf("*");
        for(j=0; j<2*(N-i); j++)
            printf(" ");
        for(j=0; j<i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}