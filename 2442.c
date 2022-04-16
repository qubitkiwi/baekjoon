#include <stdio.h>

int main(void)
{
    int N, i, j;
    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        for(j=i; j<N-1; j++)
            printf(" ");
        for(j=0; j<i*2+1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}