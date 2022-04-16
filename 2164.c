#include <stdio.h>

int main(void)
{
    int N, f, r, num, max;
    int queue[500000];
    int i;
    max = 500000;
    
    scanf("%d", &N);

    for(i=0; i<N; i++)
        queue[i] = i+1;

    f = 0;
    r = i;
    num = i;

    while(num != 1)
    {
        f++;
        queue[r++] = queue[f++];
        f %= max;
        r %= max;
        num--;
    }

    printf("%d\n", queue[f]);

    return 0;
}