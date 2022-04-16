#include <stdio.h>

int main(void)
{
    int N, i, j;
    int map[125][125];
    int dp[125][125];

    while(1)
    {
        scanf("%d", &N);
        if(!N) break;

        for(i=0; i<N; i++)
            for(j=0; j<N; j++)
            {
                scanf("%d", &map[i][j]);
                dp[i][j] = 0;
            }
        
        dp[0][0] = map[0][0];

        for(i=1; i<N; i++)
        {
            dp[i][0] = dp[i-1][0] + map[i][0];
            dp[0][i] = dp[0][i-1] + map[0][i];
        }

        for(i=1; i<N; i++)
        {
            for(j=1; j<N; j++)
            {
                dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i-1][j]+map[i][j]: dp[i][j-1]+map[i][j];
            }
        }

        

        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
                printf("%d ", dp[i][j]);
            printf("\n");
        }



    }

    return 0;
}