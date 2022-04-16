#include <stdio.h>

int main(void)
{ 
    int N, i, j, max, min;
    int in[3], dp[2][3] = {0, }, T[3];

    scanf("%d", &N);

    scanf("%d %d %d", &in[0], &in[1], &in[2]);
    for(i=0; i<3; i++)
    {
        dp[0][i] = in[i];
        dp[1][i] = in[i];
    }

    for(i=1; i<N; i++)
    {
        scanf("%d %d %d", &in[0], &in[1], &in[2]);
        T[0] = dp[0][0]>dp[0][1] ? dp[0][0]+in[0] : dp[0][1]+in[0];
        T[2] = dp[0][1]>dp[0][2] ? dp[0][1]+in[2] : dp[0][2]+in[2];

        max = dp[0][0];
        for(j=1; j<3; j++)
            if(max < dp[0][j])
                max = dp[0][j];
        T[1] = max + in[1];

        for(j=0; j<3; j++)
            dp[0][j] = T[j];


        T[0] = dp[1][0]<dp[1][1] ? dp[1][0]+in[0] : dp[1][1]+in[0];
        T[2] = dp[1][1]<dp[1][2] ? dp[1][1]+in[2] : dp[1][2]+in[2];

        min = dp[1][0];
        for(j=1; j<3; j++)
            if(min > dp[1][j])
                min = dp[1][j];
        T[1] = min + in[1];

        for(j=0; j<3; j++)
            dp[1][j] = T[j];
    }

    max = dp[0][0];
    for(i=1; i<3; i++)
        if(max < dp[0][i])
            max = dp[0][i];

    min = dp[1][0];
    for(i=1; i<3; i++)
        if(min > dp[1][i])
            min = dp[1][i];

    printf("%d %d\n", max, min);
    return 0;
}