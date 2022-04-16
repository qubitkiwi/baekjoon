#include <stdio.h>

int main(void)
{
    int N, i, j, t, cnt, max=0;
    scanf("%d", &N);
    int arr[N];

    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<N; i++)
    {
        cnt = 0;
        for(j=i+1; j<N; j++)
        {
            if(arr[i] > arr[j])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        if(max < cnt)
        {
            max = cnt;
        }
    }

    printf("%d\n", max);

    return 0;
}