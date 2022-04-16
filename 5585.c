#include <stdio.h>

int main(void)
{
    int N, i, j, cnt=0;
    int m[6] = {500, 100, 50, 10, 5, 1};

    scanf("%d", &N);

    N = 1000-N;
    
    for(i=0; i<sizeof(m)/sizeof(int); i++)
    {
        if(N/m[i]>0)
        {
            cnt += N/m[i];
            N %= m[i];            
        }
    }

    printf("%d\n", cnt);

    return 0;
}