#include <stdio.h>

int main(void)
{
    int N, i;
    int P[46];
    
    P[0] = 0;
    P[1] = 1;
    P[2] = 1;

    scanf("%d", &N);

    for(i=3; i<=N; i++)
        P[i] = P[i-1] + P[i-2];
    
    printf("%d\n", P[N]);
    return 0;
}