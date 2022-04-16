#include <stdio.h>

int dp[1001][1001];

int binomial_coefficient(int N, int K)
{
    int i, j;

    for(i=0; i<=N; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
        
    // if(N/2<K)
    //     K = N-K;

    for(i=2; i<=N; i++)
        for(j=1; j<i ; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;

    return dp[N][K];
}

int main(void)
{
    int N, K;
    int anw;
    scanf("%d %d", &N, &K);
    anw = binomial_coefficient(N, K);
    // anw %= 10007;

    printf("%d\n", anw);
    return 0;
}