#include <stdio.h>

int main(void)
{
    int n, i, j, max;
    int tree[500][500];
    int dp[500][500];

    scanf("%d", &n);

    for(i=0; i<n; i++)
        for(j=0; j<i+1; j++)
            scanf("%d", &tree[i][j]);
    
    dp[0][0] = tree[0][0];

    for(i=1; i<n; i++)
    {
        dp[i][0] = dp[i-1][0] + tree[i][0];
        dp[i][i] = dp[i-1][i-1] + tree[i][i];
    }

    for(i=2; i<n; i++)
        for(j=1; j<i; j++)
            dp[i][j] = dp[i-1][j-1] > dp[i-1][j] ? dp[i-1][j-1]+tree[i][j] : dp[i-1][j]+tree[i][j]; 


    max = dp[n-1][0];
    for(i=1; i<n; i++)
        if(max < dp[n-1][i])
            max = dp[n-1][i];

    printf("%d\n", max);

    return 0;
}