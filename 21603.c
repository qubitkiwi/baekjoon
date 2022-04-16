#include <stdio.h>

int main(void)
{
    int N, K, i, cnt=0;
    scanf("%d %d", &N, &K);
    int arr[N];

    for (i=1; i<=N; i++)
    {
        if(i%10 != K%10 && i%10 != (2*K)%10)
        {
            arr[cnt] = i;
            cnt++;
        }
    }

    printf("%d\n", cnt);

    for (i=0; i<cnt; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}