#include <stdio.h>

int binomial_coefficient(int N, int K)
{
    int i, result = 1;

    for(i=N-K+1; i<=N; i++)
        result *= i;

    for(i=2; i<=K; i++)
        result /= i;

    return result;
}

int main(void)
{
    int N, K, anw;
    scanf("%d %d", &N, &K);
    anw = binomial_coefficient(N, K);
    
    printf("%d\n", anw);
    return 0;
}