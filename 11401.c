#include <stdio.h>

int dp[2000001][2000001];

int binomial_coefficient(int N, int K)
{
    int i, j;

    for(i=0; i<=N; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
        
    if(N/2<K)
        K = N-K;

    for(i=2; i<=N; i++)
        for(j=1; j<i && j<=K; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000007;

    return dp[N][K];
}

int main(void)
{
    int N, K;
    int anw;
    scanf("%d %d", &N, &K);
    anw = binomial_coefficient(N, K);

    printf("%d\n", anw);
    return 0;
}