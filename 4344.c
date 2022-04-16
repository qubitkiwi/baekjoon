#include <stdio.h>

int main(void)
{
    int T, tc, N, i, j, sum;
    double avg, cnt;

    scanf("%d", &T);

    for(tc=0; tc<T; tc++)
    {
        scanf("%d", &N);

        sum = avg = cnt = 0;

        int arr[N];
        for(i=0; i<N; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }

        avg = sum/N;

        for(i=0; i<N; i++)
            if(arr[i] > avg)
                cnt++;
        
        printf("%.3f%%\n", cnt/N*100);
    }
    return 0;
}