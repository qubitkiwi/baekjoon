#include <stdio.h>

int main(void)
{
    int A[2][1000] = {0,};
    int dp[1000];
    int i, N, dp_p=0;

    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d", &A[0][i]);
    
    A[1][0] = 1;
    dp[dp_p++] = A[0][0];

    for(i=1; i<N; i++)
    {
        if(dp[dp_p-1] < A[0][i])
        {
            sdd
        }
    }



    return 0;
}