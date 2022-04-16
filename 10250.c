#include <stdio.h>

int main(void)
{
    int T, tc, y, x;
    int H, W, N;
    scanf("%d", &T);

    for(tc=0; tc<T; tc++)
    {
        scanf("%d %d %d", &H, &W, &N);

        y = N%H ? N%H : H;
        x = (N-1)/H+1;

        if(x<10)
            printf("%d0%d\n", y,x);
        else
            printf("%d%d\n", y,x);
    }
    return 0;
}