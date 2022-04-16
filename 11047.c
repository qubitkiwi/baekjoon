#include <stdio.h>

int main(void)
{
    int N, K, i, j, cnt=0;
    scanf("%d %d", &N, &K);

    int money[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &money[i]);
    }

    i = N-1;

    while(K>0)
    {
        
        if(K - money[i] >= 0)
        {
            K -= money[i];
            cnt++;
        }
        else
        {
            i--;
        }
    }

    printf("%d\n", cnt);

    return 0;
}