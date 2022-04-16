#include <stdio.h>

int main(void)
{
    int RGB[1000][3];
    int dp[1000][3];
    int N, i, min;
    scanf("%d", &N);

    for(i=0; i<N; i++)
        scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);

    for(i=0; i<3; i++)
        dp[0][i] = RGB[0][i];
    
    for(i=1; i<N; i++)
    {
        dp[i][0] = dp[i-1][1]+RGB[i][0] < dp[i-1][2]+RGB[i][0] ? dp[i-1][1]+RGB[i][0] : dp[i-1][2]+RGB[i][0];
        dp[i][1] = dp[i-1][0]+RGB[i][1] < dp[i-1][2]+RGB[i][1] ? dp[i-1][0]+RGB[i][1] : dp[i-1][2]+RGB[i][1];
        dp[i][2] = dp[i-1][0]+RGB[i][2] < dp[i-1][1]+RGB[i][2] ? dp[i-1][0]+RGB[i][2] : dp[i-1][1]+RGB[i][2];
    }

    min = dp[N-1][0];
    for(i=1; i<3; i++)
        if(min > dp[N-1][i])
            min = dp[N-1][i];

    printf("%d\n", min);

    return 0;
}