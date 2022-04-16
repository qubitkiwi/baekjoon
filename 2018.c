#include <stdio.h>

int main(void)
{
    int N, i, j, sum, cnt=0;
    scanf("%d", &N);

    for(i=1; i<=N/2; i++)
    {
        sum = 0;
        for(j=i; j<=N/2+1; j++)
        {
            sum += j;
            if(sum == N)
            {
                cnt++;
                break;
            }   
            if(sum > N)
            {
                break;
            }
        }
    }

    printf("%d\n", cnt+1);

    return 0;
}